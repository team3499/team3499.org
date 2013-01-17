#ifndef DERPPAGE_H
#define DERPPAGE_H

#include "request.hpp"
#include "reply.hpp"
#include "global.h"
#include "zstring.h"
#include "pagescommon.h"

class DerpPage {
public:
    DerpPage();
    void page(Request &request, Reply &reply);
};

#endif // DERPPAGE_H
