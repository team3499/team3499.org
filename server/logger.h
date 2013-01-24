#ifndef LOGGER_H
#define LOGGER_H

#include <boost/thread.hpp>
#include <iostream>
#include "zstring.h"
#include "zfile.h"

class Logger {
public:
    Logger();
    ~Logger();
    Logger &operator<<(ZString);
private:
    ZFile logfile;
};

#endif // LOGGER_H
