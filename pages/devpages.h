#ifndef DEVPAGES_H
#define DEVPAGES_H

#include "pagebase.h"

namespace DevPages {

class DumpPage : public PageBase {
public:
    DumpPage();
    void page(Request &request, Reply &reply);
    ZString args();
    ZString tooltip();
    ZString help();
};

class DerpPage : public PageBase {
public:
    DerpPage();
    void page(Request &request, Reply &reply);
    ZString args();
    ZString tooltip();
    ZString help();
};

}

#endif // DEVPAGES_H
