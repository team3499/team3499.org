#ifndef HELPPAGE_H
#define HELPPAGE_H

#include "pagebase.h"
#include "pages.h"

class HelpPage {
public:
    HelpPage();
    static void page(Request &request, Reply &reply);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};

#endif // HELPPAGE_H
