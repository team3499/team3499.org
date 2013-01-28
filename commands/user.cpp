#include "user.h"
#include "database.h"

User::User(){}

void UserLogin::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Login";
    values["style"] = "";
    values["script"] = "";
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
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Login";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
ZString UserLogin::args(){
    return "none";
}
ZString UserLogin::tooltip(){
    return "Logs a user in";
}
ZString UserLogin::help(){
    return "This command links the current session to a user, and loads user-specific settings to the session, if applicable.";
}

void UserLogout::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Logout";
    values["style"] = "";
    values["script"] = "";
    req.sess.reset();
    ZString cont;
    ZFile fl("parts/commands/logout.html");
    cont = fl.read();
    fl.close();
    if(req.sess.loggedin)
        cont.label("response", "Logged Out");
    else
        cont.label("response", "You weren't Logged In to begin with, but Okay.");
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Login";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
ZString UserLogout::args(){
    return "none";
}
ZString UserLogout::tooltip(){
    return "Logs the current user out";
}
ZString UserLogout::help(){
    return "This command removes all references to the current user from the current session, and wipes the session.";
}

void MePage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Me";
    values["style"] = "";
    values["script"] = "";
    ZString cont;
    ZFile fl("parts/pages/me.html");
    cont = fl.read();
    fl.close();
    cont.label("uid", req.sess.userdat.uid);
    cont.label("uname", req.sess.userdat.name);
    cont.label("perms", req.sess.userdat.perms);
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Login";
    values["prompttxt"] = "Awaiting Command...";
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
