#include "derppage.h"

DerpPage::DerpPage(){}

void DerpPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Derp";
    values["style"] = "";
    values["script"] = "";
    ZString cont = ZString(HOME_TITLE("Derp")) + "<div id='contentbox'><div id='content'>";
    cont += "<div class=\"default-wrapper\"><p class=\"content-body\">Derp Content:";
    cont += "Derp a Derpy Derp</div>""</div></div>";
    //cont.replace("&", "&amp;");
    //cont.replace("<", "&lt;");
    //cont.replace(">", "&gt;");
    values["contout"] = cont;
    values["shellout"]= "Derp Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
