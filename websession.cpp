#include "websession.h"

WebSession::WebSession(){
    //sessdb.open(SESSIONDB);
    index = 0;
    loggedin = false;
}

string WebSession::randomId(int len){
    srand((unsigned)time(0));
    string s;
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!?@#$%&*+-";
    for(int i = 0; i < len; ++i){
        s += alphanum[rand() % (sizeof(alphanum) -1)];
    }
    return s;
}
ZString WebSession::generateId(){
    string tmpid = randomId(20);
    QDir dir(SESSION_PATH);
    QList<QFileInfo> flist = dir.entryInfoList();
    for(int i = 0; i < flist.size(); ++i){
        if(flist[i].isFile()){
            if(flist[i].fileName() == ZString(tmpid).QS()){
                tmpid = randomId(20);
                i = -1;
            }
        }
    }
    return ZString(tmpid);
}

void WebSession::reset(){
    userdat.uid = 0;
    userdat.name = "Guest";
    userdat.perms = 0;
}

void WebSession::update(){
    AsArZ sessdata;
    sessdata["id"] = sessid;
    sessdata["userid"] = ZString(userdat.uid);
    sessdata["username"] = userdat.name;
    sessdata["perms"] = ZString(userdat.perms);
    //sessdata["expires"] = QDateTime::currentDateTime().currentMSecsSinceEpoch();
    ZString datstr;
    datstr.toJSON(sessdat);
    sessdata["data"] = datstr;
    ZString sessdatstr;
    sessdatstr.toJSON(sessdata);
    ZString sessflnm = SESSION_PATH;
    sessflnm += sessid;

    ZFile sessfl(WRITE, sessflnm);
    sessfl.write(sessdatstr);
    sessfl.close();
}

bool WebSession::exists(ZString sessioncookie){
    QDir dir(SESSION_PATH);
    QList<QFileInfo> flist = dir.entryInfoList();
    for(int i = 0; i < flist.size(); ++i){
        if(flist[i].isFile()){
            if(flist[i].fileName() == sessioncookie.QS()){
                return true;
            }
        }
    }
    return false;
}

void WebSession::updateSessions(){
    QDir dir(SESSION_PATH);
    QList<QFileInfo> flist = dir.entryInfoList();
    for(int i = 0; i < flist.size(); ++i){
        if(flist[i].isFile()){
            qint64 ftime = flist[i].lastModified().currentMSecsSinceEpoch();
            qint64 ctime = QDateTime::currentDateTime().currentMSecsSinceEpoch();
            if(ctime - LIFE_MSECS > ftime){
                QFile bfile(flist[i].absoluteFilePath());
                bfile.remove();
            }
        }
    }
}

void WebSession::readData(){
    ZFile sessfl(READ, ZString(SESSION_PATH) + sessid);
    AsArZ tmp = sessfl.read().fromJSON();
    userdat.uid = tmp["userid"].tint();
    userdat.name = tmp["username"];
    userdat.perms = tmp["perms"].tint();
    sessdat = tmp["data"].fromJSON();
}

AsArZ WebSession::data(){
    return sessdat;
}
