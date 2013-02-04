#ifndef ZSTRING_H
#define ZSTRING_H

#include <string>
#include <sstream>
#include <cstring>
#ifdef ZSTRING_USE_QT
    #include <QString>
    #include <QByteArray>
#endif
#include "asar.h"
#include <cstdlib>

class ZString;
typedef AssocArray<ZString> AsArZ;

class ZString {
public:
    ZString();

    ZString &operator=(ZString);
    bool operator==(ZString);
    bool operator!=(ZString);
    ZString operator+(ZString);
    ZString &operator+=(ZString);
    ZString &operator<<(ZString);

    ZString(std::string);
    ZString &operator=(std::string);
    bool operator==(const std::string);
    bool operator!=(const std::string);
    ZString operator+(std::string);
    ZString &operator+=(std::string);
    ZString &operator<<(std::string);
    std::string &str();

#ifdef ZSTRING_USE_QT
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
    bool operator==(char*);
    bool operator!=(char*);
    ZString operator+(char*);
    ZString &operator+=(char*);
    ZString &operator<<(char*);
    char *c();

    ZString(const char*);
    ZString &operator=(const char*);
    bool operator==(const char*);
    bool operator!=(const char*);
    ZString operator+(const char*);
    ZString &operator+=(const char*);
    ZString &operator<<(const char*);
    const char *cc();

    ZString(char); // May or may not work
    ZString &operator=(char);
    ZString operator+(char);
    ZString &operator+=(char);
    ZString &operator<<(char);

#ifdef ZSTRING_USE_QT
    ZString(qint64);
#endif
    ZString(int);
    int tint();

    int size();
    int length();
    int count(std::string);

    ZString replace(std::string before, std::string after, bool modify = true);
    ZString label(std::string label, ZString value, bool modify = true);
    ZString label(AsArZ, bool modify = true);
    ZString strip(char target, bool modify = true);
    ZString substr(int, bool modify = true);
    ZString substr(int, int, bool modify = true);
    ZString invert(bool modify = true);
    ZString toLower(bool modify = true);

    AsArZ explode(char delim);
    AsArZ strict_explode(char delim);
    AsArZ explode();

    ZString toJSON(AsArZ, bool modify = true);
    bool validJSON();
    AsArZ fromJSON();

    friend ostream &operator<<(ostream& lhs, ZString rhs);
private:
    std::string data;
};

#endif // ZSTRING_H
