#include "helppage.h"

HelpPage::HelpPage(){}

void HelpPage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "ZS - Help";
    values["style"] = "";
    values["script"] = "";
    ZString cont;

    if(req.comm[1].str() != ""){
        ZFile helpfl("parts/pages/helpcom.html");
        cont = helpfl.read();
        if(req.comm[1] == HOME){
            cont.label("command_name", "Home");
            cont.label("command_help", HomePage::help());
        } else if(req.comm[1] == DERP){
            cont.label("command_name", "Derp");
            cont.label("command_help", DevPages::DerpPage::help());
        } else if(req.comm[1] == DUMP){
            cont.label("command_name", "Dump");
            cont.label("command_help", DevPages::DumpPage::help());
        } else if(req.comm[1] == ABOUT){
            cont.label("command_name", "About");
            cont.label("command_help", AboutPage::help());
        } else if(req.comm[1] == HELP){
            cont.label("command_name", "Help");
            cont.label("command_help", HelpPage::help());
        } else if(req.comm[1] == RAYTRACE){
            cont.label("command_name", "RayTrace");
            cont.label("command_help", RayTracePage::help());
        } else {
            cont.label("command_name", "Unknown");
            cont.label("command_help", "Unknown command or page, or no help available.");
        }
    } else {
        ZFile helpfl("parts/pages/help.html");
        cont = helpfl.read();
        helpfl.close();

        cont.label("home_args", HomePage::args());
        cont.label("home_tooltip", HelpPage::tooltip());
        cont.label("help_args", HelpPage::args());
        cont.label("help_tooltip", HelpPage::tooltip());
        cont.label("derp_args", DevPages::DerpPage::args());
        cont.label("derp_tooltip", DevPages::DerpPage::tooltip());
        cont.label("dump_args", DevPages::DumpPage::args());
        cont.label("dump_tooltip", DevPages::DumpPage::tooltip());
        cont.label("about_args", AboutPage::args());
        cont.label("about_tooltip", AboutPage::tooltip());
        cont.label("raytrace_args", RayTracePage::args());
        cont.label("raytrace_tooltip", RayTracePage::tooltip());
    }

    cont.replace("\n", "");
    cont.replace("\r", "");
    cont.replace("    ", "");
    values["contout"] = cont;
    values["shellout"]= "Help Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
ZString HelpPage::args(){
    return "[command]";
}
ZString HelpPage::tooltip(){
    return "Help Page";
}
ZString HelpPage::help(){
    return "This page gives inforamtion about the various commands and pages on this site.";
}
