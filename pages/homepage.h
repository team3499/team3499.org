#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "pagebase.h"

class HomePage {
public:
    HomePage();
    static void page(Request &request, Reply &reply);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};

#endif // HOMEPAGE_H
