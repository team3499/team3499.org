#include "gallerypage.h"

GalleryPage::GalleryPage(){}

void GalleryPage::page(Request &req, Reply &rep){
    values["path"] = "/";
    values["pagetitle"] = "3499 - Gallery";
    ZFile srcfl("parts/pages/gallery.css");
    ZString style = srcfl.read();
    srcfl.close();
    style.replace("    ", "");
    style.replace("\n", "");
    style.replace("\r", "");
    values["style"] = style;
    ZString cont;
    if(req.comm[1] == "2012"){
        ZFile fl("parts/pages/gallery2012.html");
        cont = fl.read();
        fl.close();
    } else {
        ZFile fl("parts/pages/gallery.html");
        cont = fl.read();
        fl.close();
    }
    values["contout"] = cont;
    values["shellout"]= "Shell Here";
    finalDoc(req, rep, values);
}
ZString GalleryPage::args(){
    return "none";
}
ZString GalleryPage::tooltip(){
    return "Gallery of pictures of the team";
}
ZString GalleryPage::help(){
    return "This page contains the galleries of the team's pictures and various images. ";
}
