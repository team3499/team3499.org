#ifndef ZFILE_H
#define ZFILE_H

#include "zstring.h"
#ifdef ZFILE_USE_QT
    #include <QFile>
    #include <QTextStream>
#else
    #include <fstream>
#endif

#define READ 1001
#define WRITE 1002
#define READWRITE 1003

class ZFile {
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
        static ZString readFile(ZString name);
        bool append(ZString);
        bool write(ZString);
        bool remove();
        bool exists(ZString);
    private:
        void setMode(int);
        bool opened;
        bool readable;
        bool writeable;
        //std::fstream *file;
#ifdef ZFILE_USE_QT
        QFile *fl;
#else
        //std::ifstream *in;
        //std::ofstream *out;
        std::fstream file;
#endif
};

#endif // ZFILE_H
