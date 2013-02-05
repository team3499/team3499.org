#include "homepage.h"

HomePage::HomePage(){}

void HomePage::page(Request &req, Reply &rep){
    values["path"] = "/";
    values["pagetitle"] = "Team 3499";
    ZFile srcfl("parts/pages/home.js");
    ZString script = srcfl.read();
    srcfl.close();
    script.replace("    ", "");
    script.replace("\n", "");
    script.replace("\r", "");
    values["script"] = script;
    ZFile homefl("parts/pages/home.html");
    ZString cont = homefl.read();
    homefl.close();
    values["contout"] = cont;
    values["shellout"]= "Shell Here";
    finalDoc(req, rep, values);
}
ZString HomePage::args(){
    return "none";
}
ZString HomePage::tooltip(){
    return "Site Home Page";
}
ZString HomePage::help(){
    return "This page is the home page for the Zennix Studios webpage.";
}
