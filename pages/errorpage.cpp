#include "errorpage.h"

ErrorPage::ErrorPage(){}

void ErrorPage::page(int mode, Request &req, Reply &rep){
    switch(mode){
    case MISSING:
        missing(req, rep);
        break;
    case BAD_REQUEST:
        bad_request(req, rep);
        break;
    default:
        missing(req, rep);
        break;
    }
}
void ErrorPage::missing(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Missing";
    values["style"] = "";
    values["script"] = "";
    ZFile errorfl("parts/pages/errors/missing.html");
    ZString cont = errorfl.read();
    ZString path;
    for(unsigned i = 0; i < req.comm.size(); ++i){
        path += req.comm[i];
        if(req.ajax)
            path += " ";
        else
            path += "/";
    }
    //cont.substr(0, cont.size() - 1, true);
    cont.label("path", path);
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Not Here";
    values["prompttxt"] = "Awaiting Command...";
    //rep.status = Reply::not_found;
    finalDoc(req, rep, values);
}
void ErrorPage::bad_request(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Missing";
    values["style"] = "";
    values["script"] = "";
    ZFile errorfl("parts/pages/errors/bad_request.html");
    ZString cont = errorfl.read();
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Not Here";
    values["prompttxt"] = "Awaiting Command...";
    //rep.status = Reply::bad_request;
    finalDoc(req, rep, values);
}

