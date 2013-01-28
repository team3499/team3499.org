#ifndef GLOBAL_H
#define GLOBAL_H

#include "logger.h"

// Generated Constants
//#ifndef BUILDING
//    #include "generated.h"
//#else
//    #include "gen.h"
//#endif

// Hard Constants
#define COOKIE_NAME "zsession"

#define USERDB "db/users.db"
#define SITEDATADB "db/site.db"

#define SESSIONDB "db/session.db"
#define SESSIONTABLE "Sessions"

#define SESSION_PATH "sessions/"
#define LIFE_SECS  7*24*60*60
#define LIFE_MSECS 7*24*60*60*1000

// Code Constants
#define STAMP ZString(QDateTime::currentDateTime().toString("dd-MM-yy hh:mm:ss")).str() << " -" << boost::this_thread::get_id() << "- "
//#define LOG(A) cout << STAMP A << endl;
#define LOG(A) Logger() << STAMP << A << "\n";
#define IF_LOG(A, B, C, D) if(A){ LOG( B << ": " << C ) } else { LOG( B << ": " << D ) }

// Contenet Macros
#define HOME_TITLE(A) "<div id='titlebox'><div id='titlecontent'><p class='home-title'>" A "</p></div></div>"

#endif // GLOBAL_H
