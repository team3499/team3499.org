#include "helppage.h"

HelpPage::HelpPage(){}

void HelpPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Help";
    values["style"] = "";
    values["script"] = "";
    ZFile derpfl("parts/pages/help.html");
    ZString cont = derpfl.read();
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Help Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
