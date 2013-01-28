#ifndef LOGGER_H
#define LOGGER_H

#include <boost/thread.hpp>
#include <iostream>
#include "zstring.h"
#include "zfile.h"
#include <QString>

class Logger {
public:
    Logger();
    ~Logger();
    void flush();
    Logger &operator<<(ZString text);
    Logger &operator<<(QString text);
    Logger &operator<<(std::string text);
    Logger &operator<<(int text);
    Logger &operator<<(const char *text);
    Logger &operator<<(char *text);
    Logger &operator<<(boost::thread::id);
private:
    //ZFile logfile;
    ZString buffer;
    ofstream logfile;
};

#endif // LOGGER_H
