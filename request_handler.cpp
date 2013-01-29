#include "request_handler.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "mime_types.hpp"
#include "reply.hpp"
#include "request.hpp"
#include "pages.h"
#include "logger.h"

using namespace std;

RequestHandler::RequestHandler(const std::string& doc_root) : doc_root_(doc_root){}

void RequestHandler::handle_request(Request &req, Reply &rep){
    LOG("-- " << req.method << " Request Handling Started --")
    //LOG("RequestHandler: Path: " << req.uri)
    if(req.method == "POST")
        req.ispost = true;
    else
        req.ispost = false;
    if(!urlDecode(req.uri, req.rawpath)){
        ErrorPage().page(BAD_REQUEST, req, rep);
        return;
    }
    req.path = ZString(req.rawpath).explode('/').shift();
    req.reqbody = getReqBody(req);
    req.postvars = getPost(req);
    getSession(req, rep);

    if(req.postvars["a"].str() != ""){
        req.ajax = true;
        req.rawcommand = req.postvars["a"];
        req.comm = req.rawcommand.explode(' ');
    } else {
        req.ajax = false;
        req.comm = req.path;
    }
    IF_LOG(req.ajax, "RequestHandler", "Using AJAX", "Using URL")

    ZString tmplog;
    for(unsigned i = 0; i < req.comm.size(); ++i){
        tmplog << " -" << req.comm[i].str() << "-";
    }
    LOG("RequestHandler: CleanPath:" << tmplog)

    commandSwitch(req, rep);

    req.sess.update();
    LOG("== Request Handling Finished ==")
    return;
}

void RequestHandler::commandSwitch(Request &req, Reply &rep){
    ZString com = req.comm[0].toLower(false);
    int perms = req.sess.userdat.perms;
    bool matched = true;

    switch(com.length()){
    case 0:
        HomePage().page(req, rep);
        break;
    case 2:
        if(com == ME)
            MePage().page(req, rep);
        else
            matched = false;
        break;
    case 4:
        if(com == HOME)
            HomePage().page(req, rep);
        else if(com == DERP)
            DevPages::DerpPage().page(req, rep);
        else if(com == HELP)
            HelpPage().page(req, rep);
        else if(com == DUMP && perms >= 2)
            DevPages::DumpPage().page(req, rep);
        else if(com == "core")
            staticFile(req, rep);
        else
            matched = false;
        break;
    case 5:
        if(com == ABOUT)
            AboutPage().page(req, rep);
        else if(com == LOGIN)
            User::Login().page(req, rep);
        else
            matched = false;
        break;
    case 6:
        if(com == LOGOUT)
            User::Logout().page(req, rep);
        else
            matched = false;
        break;
    case 8:
        if(com == RAYTRACE && perms >= 2)
            RayTracePage().page(req, rep);
        else
            matched = false;
        break;
    case 11:
        if(com == "favicon.ico")
            staticFile(req, rep);
        else
            matched = false;
        break;
    default:
        matched = false;
        break;
    }
    if(!matched)
        ErrorPage().page(MISSING, req, rep);
}

ZString RequestHandler::getReqBody(Request req){
    ZString body = req.raw_request;
    body.replace(req.raw_headers, "");
    return body;
}

AsArZ RequestHandler::getPost(Request req){
    AsArZ out;
    if(req.headers["Content-Length"].str() != ""){
        int len = atoi(req.headers["Content-Length"].cc());
        ZString buff = req.reqbody.str().substr(0, len);
        AsArZ first = buff.explode('&');
        for(unsigned i = 0; i < first.size(); ++i){
            AsArZ second = first[i].explode('=');
            out[second[0].str()] = second[1];
        }
    }
    return out;
}

bool RequestHandler::urlDecode(std::string in, ZString& out){
    for(size_t i = 0; i < in.size(); ++i){
        if(in[i] == '%'){
            if(i + 3 <= in.size()){
                int value = 0;
                istringstream is(in.substr(i + 1, 2));
                if(is >> hex >> value){
                    out += static_cast<char>(value);
                    i += 2;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else if(in[i] == '+'){
            out += ' ';
        } else {
            out += in[i];
        }
    }
    return true;
}

void RequestHandler::staticFile(Request &req, Reply &rep){
    std::string request_path = req.rawpath.str();
    /*if (!urlDecode(req.uri, request_path)){
        rep = Reply::stock_reply(Reply::bad_request);
        return;
    }*/

    // Request path must be absolute and not contain "..".
    if (request_path.empty() || request_path[0] != '/' || request_path.find("..") != std::string::npos){
        rep = Reply::stock_reply(Reply::bad_request);
        return;
    }

    // If path ends in slash (i.e. is a directory) then add "index.html".
    if (request_path[request_path.size() - 1] == '/'){
        request_path += "index.html";
    }

    // Determine the file extension.
    std::size_t last_slash_pos = request_path.find_last_of("/");
    std::size_t last_dot_pos = request_path.find_last_of(".");
    std::string extension;
    if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos){
        extension = request_path.substr(last_dot_pos + 1);
    }

    ZFile staticfl;
    if(!staticfl.open(doc_root_ + request_path)){
        rep = Reply::stock_reply(Reply::not_found);
        return;
    }
    rep.status = Reply::ok;
    rep.content = staticfl.read();
    rep.headers["Content-Length"] = rep.content.length();
    rep.headers["Content-Type"] = MimeTypes::extension_to_type(extension);
    rep.headers["Cache-Control"] = "max-age=3600, must-revalidate";
}
