#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include "pagebase.h"

class AboutPage {
public:
    AboutPage();
    static void page(Request &request, Reply &reply);
};

#endif // ABOUTPAGE_H
