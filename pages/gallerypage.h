#ifndef GALLERYPAGE_H
#define GALLERYPAGE_H

#include "pagebase.h"

class GalleryPage : public PageBase {
public:
    GalleryPage();
    void page(Request &request, Reply &reply);
    ZString args();
    ZString tooltip();
    ZString help();
};

#endif // GALLERYPAGE_H
