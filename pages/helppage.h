#ifndef HELPPAGE_H
#define HELPPAGE_H

#include "request.hpp"
#include "reply.hpp"
#include "global.h"
#include "zstring.h"
#include "pagescommon.h"

class HelpPage {
public:
    HelpPage();
    void page(Request &request, Reply &reply);
};

#endif // HELPPAGE_H
