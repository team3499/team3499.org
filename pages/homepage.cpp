#include "homepage.h"

HomePage::HomePage(){}

void HomePage::page(Request &req, Reply &rep){
    AsArZ values;
    values["pagetitle"] = "Zennix Studios";
    values["style"] = "";
    values["script"] = "";
    ZString paths;
    /*for(int i = 0; i < request.path.size(); ++i){
        paths += "\"";
        paths += request.path[i];
        paths += "\" ";
    }*/
    ZString cont = ZString(HOME_TITLE("Zennix Studios")) + "<div id='contentbox'><div id='content'>";
    cont += "<div class=\"default-wrapper\"><p class=\"content-body\">Home Content:";
    cont += paths;
    cont += " ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789 !@#$%^&amp;*()&lt;&gt;[]{}:;,.?//\\/\\/\\/\\\\-_=+\"'</p><span class=\"ajax-link\" onclick=\"sendCommand('about');\">About</span></div>""</div></div>";
    //cont.replace("&", "&amp;");
    //cont.replace("<", "&lt;");
    //cont.replace(">", "&gt;");
    values["contout"] = cont;
    values["shellout"]= "Shell Here";
    values["prompttxt"] = "Awaiting Command...";
    finalDoc(req, rep, values);
}
