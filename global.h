#ifndef GLOBAL_H
#define GLOBAL_H

#include "logger.h"

// Constants
#define COOKIE_NAME "zsession"

#define SESSIONDB "db/session.db"
#define SESSIONTABLE "Sessions"

#define SESSION_PATH "sessions/"
#define LIFE_SECS  7*24*60*60
#define LIFE_MSECS 7*24*60*60*1000

// Code Constants
#define STAMP ZString(QDateTime::currentDateTime().toString("dd-MM-yy hh:mm:ss")).str() <<

// Contenet Macros
#define HOME_TITLE(A) "<div id='titlebox'><div id='titlecontent'><p class='home-title'>" A "</p></div></div>"

#endif // GLOBAL_H
