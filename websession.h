#ifndef WEBSESSION_H
#define WEBSESSION_H

#include <QDir>
#include <QList>
#include <QFileInfo>
#include <QDateTime>
#include <sstream>
#include "database.h"
#include "zfile.h"
#include "zstring.h"
#include "asar.h"
#include <fcntl.h>
#include "global.h"

class WebSession {
    public:
        WebSession();
        void setId(ZString sessionid);
        ZString getId();
        void generateId();
        void create();
        void update();
        bool exists(ZString sessionid);
        void updateSessions();
        string randomId(int length);
        void readData();
        AsArZ data();
    private:
        //Database sessdb;
        ZString sessid;
        ZString userid;
        ZString username;
        AsArZ sessdat;
        unsigned long state[16];
        unsigned int index;
        unsigned long WELLRNG512();
};

#endif // WEBSESSION_H
