#ifndef ZSTRING_H
#define ZSTRING_H

#include <string>
#include <sstream>
#include <cstring>
#ifdef USE_QT
    #include <QString>
    #include <QByteArray>
#endif
#include "asar.h"

class ZString;
typedef AssocArray<ZString> AsArZ;

class ZString {
public:
    ZString();

    ZString &operator=(ZString);
    ZString operator+(ZString);
    ZString &operator+=(ZString);
    ZString &operator<<(ZString);

    ZString(std::string);
    ZString &operator=(std::string);
    inline bool operator==(const std::string);
    ZString operator+(std::string);
    ZString &operator+=(std::string);
    ZString &operator<<(std::string);
    std::string &str();

#ifdef USE_QT
    ZString(QString);
    ZString &operator=(QString);
    inline bool operator==(const QString);
    ZString operator+(QString);
    ZString &operator+=(QString);
    ZString &operator<<(QString);
    QString QS();

    ZString(QByteArray);
    ZString &operator=(QByteArray);
    inline bool operator==(const QByteArray);
    ZString operator+(QByteArray);
    ZString &operator+=(QByteArray);
    ZString &operator<<(QByteArray);
    QByteArray QBA();
#endif

    ZString(char*);
    ZString &operator=(char*);
    inline bool operator==(char*);
    ZString operator+(char*);
    ZString &operator+=(char*);
    ZString &operator<<(char*);
    char *c();

    ZString(const char*);
    ZString &operator=(const char*);
    bool operator==(const char*);
    ZString operator+(const char*);
    ZString &operator+=(const char*);
    ZString &operator<<(const char*);
    const char *cc();

    ZString(char); // May or may not work
    ZString &operator=(char);
    ZString operator+(char);
    ZString &operator+=(char);
    ZString &operator<<(char);

#ifdef USE_QT
    ZString(qint64);
#endif
    ZString(int);

    int size();
    int length();

    int count(std::string);
    ZString &replace(std::string before, std::string after);
    void label(std::string label, ZString value);
    void label(AsArZ);
    AsArZ explode(char delim);
    AsArZ strict_explode(char delim);
    AsArZ explode();
    ZString strip(char target);
    ZString &substr(int);
    ZString &substr(int, int);

    ZString toJSON(AsArZ);
    AsArZ fromJSON();
private:
    std::string data;
};

#endif // ZSTRING_H
