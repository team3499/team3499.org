#include "missingpage.h"

MissingPage::MissingPage(){}

void MissingPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Missing";
    values["style"] = "";
    values["script"] = "";
    ZString cont = ZString(HOME_TITLE("Missing")) + "<div id='contentbox'><div id='content'>";
    cont += "<div class=\"default-wrapper\"><p class=\"content-body\">Missing Content:";
    cont += "Page / Command / File not found</div>""</div></div>";
    //cont.replace("&", "&amp;");
    //cont.replace("<", "&lt;");
    //cont.replace(">", "&gt;");
    values["contout"] = cont;
    values["shellout"]= "Not Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}

