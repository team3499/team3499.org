#ifndef USER_H
#define USER_H

#include "pagebase.h"
#include "database.h"

class User {
public:
    User();
};

class UserLogin {
public:
    UserLogin();
    static void page(Request &req, Reply &rep);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};
class UserLogout {
public:
    UserLogout();
    static void page(Request &req, Reply &rep);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};

class MePage {
public:
    MePage();
    static void page(Request &req, Reply &rep);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};

#endif // USER_H
