#include "pagescommon.h"
#include "request.hpp"

void getSession(Request &request, Reply &reply){
    ZString sessioncookie;
    for(unsigned i = 0; i < request.headers.size(); ++i){
        if(request.headers.I(i) == "Cookie"){
            AsArZ tmp = parseCookie(request.headers[i]);
            sessioncookie = tmp[COOKIE_NAME];
        }
    }
    //ZString sessioncookie = request.getCookie(COOKIE_NAME);

    LOG("SessionParser: Cookie: " << sessioncookie.str())
    request.sess.updateSessions(); // Deletes Sessions Past Expiry
    // Get current session, or create a new one
    if(request.sess.exists(sessioncookie)){
        //qDebug() << "Updating Session";
        request.sess.setId(sessioncookie);
        //reply.headers["Set Cookie"] = ZString(COOKIE_NAME"=") + sessioncookie;
        request.sess.update();
        request.sess.readData();
    } else {
        //qDebug() << "Creating New Session";
        request.sess.generateId();
        reply.headers["Set Cookie"] = ZString(COOKIE_NAME"=") + sessioncookie;
        request.sess.create();
        request.sess.readData();
    }
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
        out["content"] = values["contout"];
        out["script"] = values["script"];
        out["style"] = values["style"];
        out["shell"] = values["shell"];
        reply.body = ZString().toJSON(out);
    }
    reply.content = reply.body;
    if(reply.status == 0)
        reply.status = Reply::ok;
}

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
