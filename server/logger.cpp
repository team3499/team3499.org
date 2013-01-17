#include "logger.h"

Logger::Logger(){
    logfile.open(WRITE, "logs/main.log");
}

Logger &Logger::operator<<(ZString text){
    std::cout << text.str();
    logfile.write(text);
    return *this;
}

Logger::~Logger(){
    logfile.close();
}
