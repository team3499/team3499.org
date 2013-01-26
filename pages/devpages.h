#ifndef DEVPAGES_H
#define DEVPAGES_H

#include "pagebase.h"

namespace DevPages {

class DumpPage {
public:
    DumpPage();
    static void page(Request &request, Reply &reply);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};

class DerpPage {
public:
    DerpPage();
    static void page(Request &request, Reply &reply);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};

}

#endif // DEVPAGES_H
