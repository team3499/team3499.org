#ifndef RAYTRACEPAGE_H
#define RAYTRACEPAGE_H

#include "pagebase.h"

class RayTracePage {
public:
    RayTracePage();
    static void page(Request &request, Reply &reply);
    static ZString args();
    static ZString tooltip();
    static ZString help();
};

#endif // RAYTRACEPAGE_H
