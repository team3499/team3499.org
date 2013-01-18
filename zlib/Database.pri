INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += $$PWD/database.cpp \
    lib/Database/zstring.cpp \
    lib/Database/zfile.cpp \
    lib/Database/asar.tpp

HEADERS += $$PWD/database.h \
    lib/Database/zstring.h \
    lib/Database/zfile.h \
    lib/Database/asar.h

