#ifndef PAGESCOMMON_H
#define PAGESCOMMON_H

#include "request.hpp"
#include "reply.hpp"
#include "asar.h"
#include "global.h"
#include "zfile.h"

void getSession(Request &request, Reply &response);
void finalDoc(Request &request, Reply &response, AsArZ values);
AsArZ parseCookie(ZString);

#endif // PAGESCOMMON_H
