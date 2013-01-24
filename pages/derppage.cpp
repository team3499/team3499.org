#include "derppage.h"

DerpPage::DerpPage(){}

void DerpPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Derp";
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
