#ifndef ZFILE_H
#define ZFILE_H

#include "zstring.h"
#ifdef USE_QT
    #include <QFile>
    #include <QTextStream>
#else
    #include <fstream>
#endif

#define READ 1001
#define WRITE 1002
#define READWRITE 1003

class ZFile{
    public:
        ZFile();
        ZFile(ZString);
        ZFile(int);
        ZFile(int, ZString);
        ~ZFile();
        bool open(int, ZString);
        bool open(ZString);
        void close();
        ZString read();
        bool write(ZString);
        bool remove();
        bool exists(ZString);
    private:
        bool opened;
        bool readable;
        bool writeable;
        //std::fstream *file;
#ifdef USE_QT
        QFile *fl;
#else
        std::ifstream *in;
        std::ofstream *out;
#endif
};

#endif // ZFILE_H
