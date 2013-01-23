#include "request_handler.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "mime_types.hpp"
#include "reply.hpp"
#include "request.hpp"
#include "homepage.h"
#include "derppage.h"
#include "errorpage.h"
#include "logger.h"

using namespace std;

RequestHandler::RequestHandler(const std::string& doc_root) : doc_root_(doc_root){}

void RequestHandler::handle_request(Request &req, Reply &rep){
    if(!urlDecode(req.uri, req.rawpath)){
        ErrorPage().page(BAD_REQUEST, req, rep);
        return;
    }
    req.path = ZString(req.rawpath).explode('/').shift();
    getSession(req, rep);

    //for(unsigned i = 0; i < req.headers.size(); ++i){
    //    cout << req.headers.I(i) << " : " << req.headers[i].str() << endl;
    //}

    /*if(req.getParameter("ps") != "1"){
        if(req.getParameter("a") != ""){
            req.ajax = true;
            req.rawcommand = req.getParameter("a");
            req.comm = req.rawcommand.explode(' ');
        } else {
            req.ajax = false;
            req.comm = req.path;
        }
    }*/

    req.comm = req.path;

    LOG("RequestHandler: Directing Query")
    cout << STAMP "RequestHandler: Path=";
    for(unsigned i = 0; i < req.comm.size(); ++i){
        cout << " -" << req.comm[i].str() << "-";
    }
    cout << endl;

    //Logger log;
    //log << "Some Text\n";

    if(req.comm[0] == "" || req.comm[0] == "home"){
        HomePage().page(req, rep);
    } else if(req.comm[0] == "derp"){
        DerpPage().page(req, rep);
    } else if(req.comm[0] == "core" || req.comm[0] == "favicon.ico"){
        staticFile(req, rep);
    } else {
        ErrorPage().page(MISSING, req, rep);
    }
    return;
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

    // Open the file to send back.
    ZFile staticfl;
    if(!staticfl.open(doc_root_ + request_path)){
        rep = Reply::stock_reply(Reply::not_found);
        return;
    }

    // Fill out the reply to be sent to the client.
    rep.status = Reply::ok;
    rep.content = staticfl.read();

    rep.headers["Content-Length"] = boost::lexical_cast<std::string>(rep.content.size());
    rep.headers["Content-Type"] = MimeTypes::extension_to_type(extension);
}
