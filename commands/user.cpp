#include "user.h"
#include "database.h"

namespace User {

Login::Login(){}

void Login::page(Request &req, Reply &rep){
    values["pagetitle"] = "ZS - Login";
    ZString cont;
    if(req.comm[1] != ""){
        if(req.comm[2] != ""){
            Database user;
            user.open(USERDB);
            ZString sql = "SELECT * FROM users WHERE uname = '";
            sql += req.comm[1];
            sql += "' AND password = '";
            sql += req.comm[2];
            sql += "'";
            ZFile fl("parts/commands/login-2.html");
            cont = fl.read();
            fl.close();
            if(user.select_rows(sql.str()) == 1){
                cont.label("loginstatus", "Login Success!");
                req.sess.userdat.uid = ZString(user.result()[0]["uid"]).tint();
                req.sess.userdat.name = user.result()[0]["uname"];
                req.sess.userdat.perms = ZString(user.result()[0]["perms"]).tint();
            } else {
                cont.label("loginstatus", "Login Failed!");
            }
        } else {
            ZFile fl("parts/commands/login-1.html");
            cont = fl.read();
            fl.close();
            cont.label("uname", req.comm[1]);
        }
    } else {
        ZFile fl("parts/commands/login-0.html");
        cont = fl.read();
        fl.close();
    }
    values["contout"] = cont;
    values["shellout"]= "Login";
    finalDoc(req, rep, values);
}
ZString Login::args(){
    return "none";
}
ZString Login::tooltip(){
    return "Logs a user in";
}
ZString Login::help(){
    return "This command links the current session to a user, and loads user-specific settings to the session, if applicable.";
}

Logout::Logout(){}

void Logout::page(Request &req, Reply &rep){
    values["pagetitle"] = "ZS - Logout";
    req.sess.reset();
    ZString cont;
    ZFile fl("parts/commands/logout.html");
    cont = fl.read();
    fl.close();
    if(req.sess.loggedin)
        cont.label("response", "Logged Out");
    else
        cont.label("response", "You weren't Logged In to begin with, but Okay.");
    values["contout"] = cont;
    values["shellout"]= "Login";
    finalDoc(req, rep, values);
}
ZString Logout::args(){
    return "none";
}
ZString Logout::tooltip(){
    return "Logs the current user out";
}
ZString Logout::help(){
    return "This command removes all references to the current user from the current session, and wipes the session.";
}

} // namespace User

MePage::MePage(){}

void MePage::page(Request &req, Reply &rep){
    values["pagetitle"] = "ZS - Me";
    ZString cont;
    ZFile fl("parts/pages/me.html");
    cont = fl.read();
    fl.close();
    cont.label("uid", req.sess.userdat.uid);
    cont.label("uname", req.sess.userdat.name);
    cont.label("perms", req.sess.userdat.perms);
    values["contout"] = cont;
    values["shellout"]= "Login";
    finalDoc(req, rep, values);
}
ZString MePage::args(){
    return "none";
}
ZString MePage::tooltip(){
    return "Information about the current user and/or session";
}
ZString MePage::help(){
    return "This page descibes the current user if one is logged in, or their session otherwise.";
}
