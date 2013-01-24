#include "aboutpage.h"

AboutPage::AboutPage(){}

void AboutPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - About";
    values["style"] = "";
    values["script"] = "";
    ZFile aboutfl("parts/pages/about.html");
    ZString cont = aboutfl.read();
    aboutfl.close();
    cont.label("build_date", BUILD_DATE);
    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "About this Site";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
