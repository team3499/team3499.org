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

    //qDebug("RequestMapper: session=%s", sessioncookie.cc());
    request.sess.updateSessions(); // Deletes Sessions Past Expiry
    // Get current session, or create a new one
    if(request.sess.exists(sessioncookie)){
        //qDebug() << "Updating Session";
        request.sess.setId(sessioncookie);
        request.headers["Set Cookie"] = ZString(COOKIE_NAME"=") + sessioncookie;
        request.sess.update();
        request.sess.readData();
    } else {
        //qDebug() << "Creating New Session";
        request.sess.generateId();
        request.headers["Set Cookie"] = ZString(COOKIE_NAME"=") + sessioncookie;
        request.sess.create();
        request.sess.readData();
    }
}

void finalDoc(Request &request, Reply &reply, AsArZ values){
    if(!request.ajax){
        reply.headers["Content-Type"] = "text/html; charset=utf-8";

        ZFile fl("parts/home.html");
        reply.body = fl.read();

        ZFile maincssfl("parts/main.css");
        ZString maincss = maincssfl.read();
        maincss.replace("\n", "");
        maincss.replace("\r", "");
        maincss.replace("    ", " ");
        reply.body.label("maincss", maincss);

        ZFile secondcssfl("parts/secondary.css");
        ZString secondcss = secondcssfl.read();
        secondcss.replace("\n", "");
        secondcss.replace("\r", "");
        secondcss.replace("    ", " ");
        reply.body.label("secondcss", secondcss);

        ZFile funcjsfl("parts/functions.js");
        ZFile mainjsfl("parts/main.js");
        ZString alljs = funcjsfl.read() + "var loadonload = \""+request.path[0]+"\";\n"  + mainjsfl.read();
        reply.body.label("mainjs", alljs);

        reply.body.label(values);
    } else {
        AsArZ out;
        out["path"] = request.rawpath;
        out["pagetitle"] = values["pagetitle"];
        out["content"] = values["contout"];
        out["script"] = values["script"];
        out["style"] = values["style"];
        out["shell"] = values["shell"];
        reply.body = ZString().toJSON(out);
    }
    reply.content += reply.body;
    //response.write(response.body.QBA(), true);
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
