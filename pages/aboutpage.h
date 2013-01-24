#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include "request.hpp"
#include "reply.hpp"
#include "global.h"
#include "zstring.h"
#include "pagescommon.h"

class AboutPage {
public:
    AboutPage();
    void page(Request &request, Reply &reply);
};

#endif // ABOUTPAGE_H
