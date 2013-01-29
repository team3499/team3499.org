#ifndef USER_H
#define USER_H

#include "pagebase.h"
#include "database.h"

namespace User {

class Login : public PageBase {
public:
    Login();
    void page(Request &req, Reply &rep);
    ZString args();
    ZString tooltip();
    ZString help();
};

class Logout : public PageBase {
public:
    Logout();
    void page(Request &req, Reply &rep);
    ZString args();
    ZString tooltip();
    ZString help();
};
}

class MePage : public PageBase {
public:
    MePage();
    void page(Request &req, Reply &rep);
    ZString args();
    ZString tooltip();
    ZString help();
};

#endif // USER_H
