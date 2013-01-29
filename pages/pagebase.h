#ifndef PAGEBASE_H
#define PAGEBASE_H

#include "request.hpp"
#include "reply.hpp"
#include "global.h"
#include "zstring.h"
#include "pagescommon.h"

class PageBase {
public:
    PageBase();
    virtual void page(Request &request, Reply &reply);
    virtual ZString args();
    virtual ZString tooltip();
    virtual ZString help();
    AsArZ values;
};

#endif // PAGEBASE_H
