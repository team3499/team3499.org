#include "request_handler.hpp"
#include "pages.h"

void RequestHandler::commandSwitch(Request &req, Reply &rep){
    ZString com = req.comm[0].toLower(false);
    int perms = req.sess.userdat.perms;
    bool matched = true;

    switch(com.length()){
    case 0:
        HomePage().page(req, rep);
        break;
    case 2:
        if(com == ME)
            MePage().page(req, rep);
        else
            matched = false;
        break;
    case 4:
        if(com == HOME)
            HomePage().page(req, rep);
        else if(com == DERP)
            DevPages::DerpPage().page(req, rep);
        else if(com == HELP)
            HelpPage().page(req, rep);
        else if(com == DUMP && perms >= 2)
            DevPages::DumpPage().page(req, rep);
        else if(com == "core")
            staticFile(req, rep);
        else
            matched = false;
        break;
    case 5:
        if(com == ABOUT)
            AboutPage().page(req, rep);
        else if(com == LOGIN)
            User::Login().page(req, rep);
        else
            matched = false;
        break;
    case 6:
        if(com == LOGOUT)
            User::Logout().page(req, rep);
        else
            matched = false;
        break;
    case 8:
        if(com == RAYTRACE && perms >= 2)
            RayTracePage().page(req, rep);
        else
            matched = false;
        break;
    case 11:
        if(com == "favicon.ico")
            staticFile(req, rep);
        else
            matched = false;
        break;
    default:
        matched = false;
        break;
    }
    if(!matched)
        ErrorPage().missing(req, rep);
}
