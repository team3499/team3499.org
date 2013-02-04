#ifndef WEBSESSION_H
#define WEBSESSION_H

#include <QDir>
#include <QList>
#include <QFileInfo>
#include <QDateTime>
#include <sstream>
#include "zfile.h"
#include "zstring.h"
#include "asar.h"
#include <fcntl.h>
#include "global.h"
#include "userdata.h"

class WebSession {
    public:
        WebSession();
        ZString generateId();
        void reset();
        void update();
        bool exists(ZString sessionid);
        void updateSessions();

        void readData();
        AsArZ data();
        //Database sessdb;
        bool loggedin;
        ZString sessid;
        UserData userdat;
        AsArZ sessdat;
        bool newsession;
private:
        unsigned long state[16];
        unsigned int index;
        string randomId(int length);
};

#endif // WEBSESSION_H
