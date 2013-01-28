#ifndef USERDATA_H
#define USERDATA_H

#include "zstring.h"

struct UserData {
    int uid;
    ZString name;
    int perms;
    AsArZ data;
};

#endif // USERDATA_H
