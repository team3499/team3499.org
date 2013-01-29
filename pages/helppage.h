#ifndef HELPPAGE_H
#define HELPPAGE_H

#include "pagebase.h"
#include "pages.h"

class HelpPage : public PageBase {
public:
    HelpPage();
    void page(Request &request, Reply &reply);
    ZString args();
    ZString tooltip();
    ZString help();
};

#endif // HELPPAGE_H
