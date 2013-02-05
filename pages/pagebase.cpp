#include "pagebase.h"

PageBase::PageBase(){
    values["pagetitle"] = "Team 3499";
    values["path"] = "";
    values["style"] = "";
    values["script"] = "";
    values["contout"] = "";
    values["shellout"]= "Command Here";
    values["prompttxt"] = "Awaiting Command...";
}

void PageBase::page(Request &request, Reply &reply){
    return;
}
ZString PageBase::args(){
    return "none";
}
ZString PageBase::tooltip(){
    return "Default tooltip";
}
ZString PageBase::help(){
    return "Place holder help page.";
}
