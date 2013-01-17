#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "request.hpp"
#include "reply.hpp"
#include "global.h"
#include "zstring.h"
#include "pagescommon.h"

class HomePage {
public:
    HomePage();
    void page(Request &request, Reply &reply);
};

#endif // HOMEPAGE_H
