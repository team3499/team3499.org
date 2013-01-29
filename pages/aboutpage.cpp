#include "aboutpage.h"

#ifndef BUILDING
    #include "generated.h"
#else
    #include "gen.h"
#endif

AboutPage::AboutPage(){}

void AboutPage::page(Request &req, Reply &rep){
    values["pagetitle"] = "ZS - About";
    ZFile aboutfl("parts/pages/about.html");
    ZString cont = aboutfl.read();
    aboutfl.close();
    cont.label("build_date", BUILD_DATE);
    values["contout"] = cont;
    values["shellout"]= "About this Site";
    finalDoc(req, rep, values);
}
ZString AboutPage::args(){
    return "none";
}
ZString AboutPage::tooltip(){
    return "Information about this website";
}
ZString AboutPage::help(){
    return "This page contains information about the website and its content, including the date of the last site rebuild.";
}
