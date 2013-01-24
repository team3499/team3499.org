#ifndef DEVPAGES_H
#define DEVPAGES_H

#include "pagebase.h"

namespace DevPages {

class DumpPage {
public:
    DumpPage();
    static void page(Request &request, Reply &reply);
};

class DerpPage {
public:
    DerpPage();
    static void page(Request &request, Reply &reply);
};

}

#endif // DEVPAGES_H
