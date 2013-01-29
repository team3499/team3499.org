#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "pagebase.h"

class HomePage : public PageBase {
public:
    HomePage();
    void page(Request &request, Reply &reply);
    ZString args();
    ZString tooltip();
    ZString help();
};

#endif // HOMEPAGE_H
