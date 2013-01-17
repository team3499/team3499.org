#include "websession.h"

WebSession::WebSession(){
    //sessdb.open(SESSIONDB);
    index = 0;
}

void WebSession::setId(ZString origid){
    sessid = origid;
}
ZString WebSession::getId(){
    return sessid;
}
void WebSession::generateId(){
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
    sessid = ZString(tmpid);
}

unsigned long WebSession::WELLRNG512(){
    unsigned long a, b, c, d;
    a = state[index];
    c = state[(index+13)&15];
    b = a^c^(a<<16)^(c<<15);
    c = state[(index+9)&15];
    c ^= (c>>11);
    a = state[index] = b^c;
    d = a^((a<<5)&0xDA442D20UL);
    index = (index + 15)&15;
    a = state[index];
    state[index] = a^b^d^(a<<2)^(b<<18)^(c<<28);
    return state[index];
}
string WebSession::randomId(int len){
    string s;
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!?@#$%&*+-";
    for(int i = 0; i < len; ++i){
        s[i] = alphanum[WELLRNG512() % (sizeof(alphanum) - 1)];
    }
    return s.substr(0, len);
}

void WebSession::create(){
    AsArZ sessdata;
    sessdata["id"] = sessid;
    sessdata["userid"] = "0";
    sessdata["username"] = "Guest";
    sessdata["perms"] = "0";
    sessdata["expires"] = QDateTime::currentDateTime().currentMSecsSinceEpoch();
    sessdata["data"] = "";
    ZString sessdatstr;
    sessdatstr.toJSON(sessdata);
    ZString sessflnm = SESSION_PATH;
    sessflnm += sessid;

    ZFile sessfl(WRITE);
    sessfl.open(sessflnm);
    sessfl.write(sessdatstr);
    //if(sessfl.write(sessdatstr))
    //    qDebug() << "Session Write Good";
    //else
    //    qDebug() << "Session Write Bad";
}

void WebSession::update(){
    ZString sessflnm = ZString(SESSION_PATH) + getId();
    ZString sessflstr;
    ZFile sessfl(sessflnm);
    sessflstr = sessfl.read();
    sessfl.remove();
    ZFile newfl(WRITE, sessflnm);
    newfl.write(sessflstr);
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
                //if(bfile.remove()){
                //    qDebug() << "Session Delete Good";
                //}else{
                //    qDebug() << "Session Delete Bad";
                //}
            }
        }
    }
}

void WebSession::readData(){
    ZFile sessfl(READ, ZString(SESSION_PATH) + sessid);
    sessdat = sessfl.read().fromJSON();
}

AsArZ WebSession::data(){
    return sessdat;
}
