#ifndef ERRORPAGE_H
#define ERRORPAGE_H

#include "request.hpp"
#include "reply.hpp"
#include "global.h"
#include "zstring.h"
#include "pagescommon.h"

#define MISSING 0x001
#define BAD_REQUEST 0x002

class ErrorPage {
public:
    ErrorPage();
    void page(int error, Request &request, Reply &reply);
    void missing(Request &request, Reply &reply);
};

#endif // ERRORPAGE_H
