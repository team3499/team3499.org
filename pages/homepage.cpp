#include "homepage.h"

HomePage::HomePage(){}

void HomePage::page(Request &req, Reply &rep){
    AsArZ values;
    values["path"] = "/";
    values["pagetitle"] = "Zennix Studios";
    values["style"] = "";
    values["script"] = "";
    ZFile homefl("parts/pages/home.html");
    ZString cont = homefl.read();
    homefl.close();
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Shell Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
