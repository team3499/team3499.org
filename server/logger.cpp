#include "logger.h"
#include "global.h"
#include <QDateTime>

Logger::Logger(){
    logfile.open(WRITE, "logs/main.log");
}

Logger &Logger::operator<<(ZString text){
    std::cout << text.str();
    IF_LOG(logfile.write(text), "Logger", "Good Write", "Bad Write")
    return *this;
}

Logger::~Logger(){
    logfile.close();
}
