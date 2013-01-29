#ifndef RAYTRACEPAGE_H
#define RAYTRACEPAGE_H

#include "pagebase.h"

class RayTracePage : public PageBase {
public:
    RayTracePage();
    void page(Request &request, Reply &reply);
    ZString args();
    ZString tooltip();
    ZString help();
};

#endif // RAYTRACEPAGE_H
