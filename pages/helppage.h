#ifndef HELPPAGE_H
#define HELPPAGE_H

#include "pagebase.h"

class HelpPage {
public:
    HelpPage();
    static void page(Request &request, Reply &reply);
};

#endif // HELPPAGE_H
