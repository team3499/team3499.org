#ifndef MISSINGPAGE_H
#define MISSINGPAGE_H

#include "request.hpp"
#include "reply.hpp"
#include "global.h"
#include "zstring.h"
#include "pagescommon.h"

class MissingPage
{
public:
    MissingPage();
    void page(Request &request, Reply &reply);
};

#endif // MISSINGPAGE_H
