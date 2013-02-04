#ifndef ERRORPAGE_H
#define ERRORPAGE_H

#include "pagebase.h"

class ErrorPage : public PageBase {
public:
    ErrorPage();
    void missing(Request &request, Reply &reply);
    void bad_request(ZString error, Request &request, Reply &reply);
};

#endif // ERRORPAGE_H
