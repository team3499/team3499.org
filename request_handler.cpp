#include "request_handler.hpp"
#include <boost/lexical_cast.hpp>
#include <sstream>
#include <string>
#include "errorpage.h"

RequestHandler::RequestHandler(const std::string& doc_root) : doc_root_(doc_root){}

void RequestHandler::handle_request(Request &req, Reply &rep){
    LOG("-- " << req.method << " Request Handling Started --")
    rep.status = Reply::undetermined;

    /*ZString tmpheads;
    for(unsigned i = 0; i < req.headers.size(); ++i){
        tmpheads << req.headers.I(i) << " : " << req.headers[i] << "\n";
    }
    LOG(tmpheads)*/

    if(!urlDecode(req.uri, req.rawpath)){
        ErrorPage().bad_request("Invalid URI (ZE0002)", req, rep);
        LOG("!! RequestHandler: Invalid URI")
        LOG("== Request Handling Finished : " << rep.status << " ==")
        return;
    }
    // Gave up on this
    /*if( req.headers["Referer"] != "" &&
        req.headers["Referer"] != "http://team3499.org/" &&
        req.headers["Referer"] != "http://www.team3499.org/" &&
        req.headers["Referer"] != "http://localhost:8080/" &&
        req.headers["Referer"] != "http://localhost/"){
        ErrorPage().bad_request("Asyncronous Request Generated from Foreign Domain (ZE0003)", req, rep);
        LOG("!! RequestHandler: Referred from Foreign Domain")
        LOG("== Request Handling Finished : " << rep.status << " ==")
        return;
    }*/
    if(req.method == "POST")
        req.ispost = true;
    else
        req.ispost = false;
    req.path = ZString(req.rawpath).explode('/').shift();

    if(req.headers["Content-Length"] != ""){
        req.reqbody = ZString(req.raw_request).replace(req.raw_headers, "", false);
        int len = atoi(req.headers["Content-Length"].cc());
        ZString buff = req.reqbody.str().substr(0, len);
        if(!buff.validJSON()){
            ErrorPage().bad_request("Invalid JSON (ZE0004)", req, rep);
            LOG("!! RequestHandler: Invalid JSON")
            LOG("== Request Handling Finished : " << rep.status << " ==")
            return;
        }
        req.postvars = buff.fromJSON();
    }
    if(req.postvars["a"] != ""){
        req.ajax = true;
        req.rawcommand = req.postvars["a"];
        req.comm = req.rawcommand.explode(' ');
    } else {
        req.ajax = false;
        req.comm = req.path;
    }
    IF_LOG(req.ajax, "RequestHandler: ", "Using AJAX", "Using URL")

    ZString tmplog;
    for(unsigned i = 0; i < req.comm.size(); ++i){
        tmplog << " -" << req.comm[i].str() << "-";
    }
    LOG("RequestHandler: CleanPath:" << tmplog)

    getSession(req, rep);

    commandSwitch(req, rep);

    req.sess.update();
    LOG("== Request Handling Finished : " << rep.status << " ==")
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
