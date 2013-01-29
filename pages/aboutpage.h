#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include "pagebase.h"

class AboutPage : public PageBase {
public:
    AboutPage();
    void page(Request &request, Reply &reply);
    ZString args();
    ZString tooltip();
    ZString help();
};

#endif // ABOUTPAGE_H
