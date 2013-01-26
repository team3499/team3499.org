#ifndef ERRORPAGE_H
#define ERRORPAGE_H

#include "pagebase.h"

#define MISSING 0x001
#define BAD_REQUEST 0x002

class ErrorPage {
public:
    ErrorPage();
    static void page(int error, Request &request, Reply &reply);
    static void missing(Request &request, Reply &reply);
    static void bad_request(Request &request, Reply &reply);
};

#endif // ERRORPAGE_H
