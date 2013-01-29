#include "pagescommon.h"
#include "request.hpp"

AsArZ parseCookie(ZString value){
    /*string val = value.str();
    for(unsigned i = 0; i < val.size(); ++i){
        switch(val[i]){
            case '=':
                val = val.susbtr(i);
            break;
        }
    }*/
    AsArZ tmp = value.explode(';');
    AsArZ cookies;
    for(unsigned i = 0; i < tmp.size(); ++i){
        AsArZ subtmp = tmp[i].explode('=');
        cookies[subtmp[0].strip(' ').str()] = subtmp[1].strip(' ');
    }
    return cookies;
}

void getSession(Request &request, Reply &reply){
    ZString sessioncookie;
    for(unsigned i = 0; i < request.headers.size(); ++i){
        if(request.headers.I(i) == "Cookie"){
            AsArZ tmp = parseCookie(request.headers[i]);
            sessioncookie = tmp[COOKIE_NAME];
        }
    }
    IF_LOG(sessioncookie == "", "SessionParser", "No Cookie Found", "Found Cookie:" << sessioncookie.str())
    request.sess.updateSessions(); // Deletes Sessions Past Expiry
    // Get current session, or create a new one
    if(!(sessioncookie == "") && request.sess.exists(sessioncookie)){
        LOG("SessionParser: Session Exists, Updating")
        request.sess.sessid = sessioncookie;
        //reply.headers["Set Cookie"] = ZString(COOKIE_NAME"=") + request.sess.sessid;
        request.sess.readData();
        if(request.sess.userdat.uid > 0)
            request.sess.loggedin = true;
        else
            request.sess.loggedin = false;
    } else {
        LOG("SessionParser: Session Doesn't Exist, Creating")
        request.sess.sessid = request.sess.generateId();
        reply.headers["Set-Cookie"] = ZString(COOKIE_NAME"=") + request.sess.sessid;
        request.sess.reset();
        request.sess.loggedin = false;
    }
    LOG("SessionParser: Session: " << request.sess.sessid.str())
}

ZString parseMacros(ZString cont, Request req, Reply rep){
    cont.label("MAIN_HEADER", ZFile("parts/common/header.html").read());
    cont.label("USERNAME", req.sess.userdat.name);
    if(req.sess.userdat.uid > 0){
        cont.label("UCOMM", "logout");
    cont.label("UCOMM_TOOLTIP", "Log Out");
    } else {
        cont.label("UCOMM", "login");
        cont.label("UCOMM_TOOLTIP", "Log In");
    }
    cont.replace("    ", "");
    cont.replace("\n", "");
    cont.replace("\r", "");
    return cont;

}

void finalDoc(Request &request, Reply &reply, AsArZ values){
    if(!request.ajax){
        reply.headers["Content-Type"] = "text/html; charset=utf-8";

        ZFile fl("parts/main.html");
        reply.body = fl.read();
        fl.close();

        ZFile maincssfl("parts/main.css");
        ZString maincss = maincssfl.read();
        maincssfl.close();
        maincss.replace("\n", "");
        maincss.replace("\r", "");
        maincss.replace("    ", " ");
        reply.body.label("maincss", maincss);

        ZFile secondcssfl("parts/secondary.css");
        ZString secondcss = secondcssfl.read();
        secondcssfl.close();
        secondcss.replace("\n", "");
        secondcss.replace("\r", "");
        secondcss.replace("    ", " ");
        reply.body.label("secondcss", secondcss);

        ZFile funcjsfl("parts/functions.js");
        ZFile mainjsfl("parts/main.js");
        ZString alljs = funcjsfl.read() + "var loadonload = \""+request.path[0]+"\";\n"  + mainjsfl.read();
        funcjsfl.close();
        mainjsfl.close();
        reply.body.label("mainjs", alljs);

        values["contout"] = parseMacros(values["contout"], request, reply);
        reply.body.label(values);
    } else {
        reply.headers["Content-Type"] = "application/json";
        AsArZ out;
        if(out["path"] == ""){
            for(unsigned i = 0; i < request.comm.size(); ++i){
                out["path"] += request.comm[i];
            }
        }
        out["pagetitle"] = values["pagetitle"];
        out["content"] = parseMacros(values["contout"], request, reply);
        out["script"] = values["script"];
        out["style"] = values["style"];
        out["shell"] = values["shell"];
        reply.body = ZString().toJSON(out);
    }
    reply.content = reply.body;
    reply.headers["Content-Length"] = reply.content.length();
    reply.headers["Cache-Control"] = "no-cache, no-store";
    if(reply.status == 0)
        reply.status = Reply::ok;
}
