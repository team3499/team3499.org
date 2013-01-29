#include "raytracepage.h"

RayTracePage::RayTracePage(){}

void RayTracePage::page(Request &req, Reply &rep){
    values["pagetitle"] = "ZS - Ray Tracer";
    ZString cont;
    if(req.comm[1] == "render"){
        //ZString time = QDateTime::currentDateTime().currentMSecsSinceEpoch();
        ZString com = "sh docroot/core/pages/raytrace/trace.sh";
        //com += time;
        //system(com.cc());
        //execl("docroot/core/pages/raytrace", "./RayTrace6");
        //execl("docroot/core/pages/raytrace", "convert traced.ppm traced.jpg");
        cont = ZString(HOME_TITLE("RayTraced Scene")) + "<div id='contentbox'><div id='content'><div class='default-wrapper'>";
        cont += "<img src='/core/pages/raytrace/traced.jpg'/>";
        cont += "</div></div></div>";
    } else {
        ZFile fl("parts/pages/raytrace.html");
        cont = fl.read();
        fl.close();
    }
    values["contout"] = cont;
    values["shellout"]= "Shell Here";
    finalDoc(req, rep, values);
}
ZString RayTracePage::args(){
    return "[render &lt;scene data&gt;]";
}
ZString RayTracePage::tooltip(){
    return "Raytracer - Does not work";
}
ZString RayTracePage::help(){
    return "This command renders a raytraced scene based on scene data sent in the command. WIP.";
}
