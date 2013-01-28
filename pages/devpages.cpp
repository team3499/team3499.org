#include "devpages.h"

namespace DevPages {

DumpPage::DumpPage(){}

void DumpPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Derp";
    values["path"] = "derp";
    values["style"] = "";
    values["script"] = "";
    ZFile derpfl("parts/pages/dump.html");
    ZString cont = derpfl.read();
    derpfl.close();

    cont.label("method", req.method);
    cont.label("uri", req.uri);
    ZString heads = "<br/>";
    for(unsigned i = 0; i < req.headers.size(); ++i){
        heads << req.headers.I(i) << " : " << req.headers[i].str() << "<br/>";
    }
    cont.label("reqheaders", heads);
    cont.label("reqbody", req.reqbody);
    ZString pvars;
    for(unsigned i = 0; i < req.postvars.size(); ++i){
        pvars << req.postvars.I(i) << " = " << req.postvars[i].str() << ", ";
    }
    cont.label("postvars", pvars);
    cont.label("sess", req.sess.sessid);
    cont.label("rawpath", req.rawpath);
    cont.label("rawcommand", req.rawcommand);
    ZString pavars;
    for(unsigned i = 0; i < req.path.size(); ++i){
        pavars << req.path[i].str() << " ";
    }
    cont.label("path", pavars);
    ZString covars;
    for(unsigned i = 0; i < req.comm.size(); ++i){
        covars << req.comm[i].str() << " ";
    }
    cont.label("comm", covars);
    if(req.ajax) cont.label("ajax", "TRUE"); else cont.label("ajax", "FALSE");

    cont.label("status", rep.status);
    ZString rheads = "<br/>";
    for(unsigned i = 0; i < rep.headers.size(); ++i){
        rheads << rep.headers.I(i) << " : " << rep.headers[i].str() << "<br/>";
    }
    cont.label("repheaders", rheads);
    cont.label("repbody", rep.body);
    cont.label("content", rep.content);

    cont.replace("\\", "\\\\");
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Dump Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
ZString DumpPage::args(){
    return "none";
}
ZString DumpPage::tooltip(){
    return "Dumps request and command parsing data";
}
ZString DumpPage::help(){
    return "This page is for debugging the request parsing methods on the server.";
}

DerpPage::DerpPage(){}

void DerpPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Derp";
    values["path"] = "derp";
    values["style"] = "";
    values["script"] = "";
    ZFile derpfl("parts/pages/derp.html");
    ZString cont = derpfl.read();
    derpfl.close();
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Derp Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
ZString DerpPage::args(){
    return "none";
}
ZString DerpPage::tooltip(){
    return "Derp";
}
ZString DerpPage::help(){
    return "This page is for simple testing.";
}

}
