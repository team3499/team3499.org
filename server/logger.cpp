#include "logger.h"
#include "global.h"
#include <QDateTime>

Logger::Logger(){}

Logger::~Logger(){
    flush();
    logfile.close();
}

void Logger::flush(){
    std::cout << buffer << std::flush;
    logfile.open("logs/main.log", ios::out | ios::app);
    logfile << buffer;
    logfile.flush();
}

Logger &Logger::operator<<(ZString text){
    buffer << text;
    return *this;
}
Logger &Logger::operator<<(QString text){
    return operator<<(ZString(text));
}
Logger &Logger::operator<<(std::string text){
    return operator<<(ZString(text));
}
Logger &Logger::operator<<(int text){
    return operator<<(ZString(text));
}
Logger &Logger::operator<<(const char *text){
    return operator<<(ZString(text));
}
Logger &Logger::operator<<(char *text){
    return operator<<(ZString(text));
}
Logger &Logger::operator<<(boost::thread::id tid){
    string text;
    stringstream stream;
    stream << tid;
    stream >> text;
    return operator<<(ZString(text));
}
