TARGET = BoostWebApp
TEMPLATE = app
CONFIG += CONSOLE

INCLUDEPATH += /usr/include
INCLUDEPATH += ./zlib
INCLUDEPATH += ./pages
INCLUDEPATH += ./server

HEADERS += \
    server/server.hpp \
    server/request_parser.hpp \
    request_handler.hpp \
    server/request.hpp \
    server/reply.hpp \
    server/mime_types.hpp \
    server/connection.hpp \
    pages/homepage.h \
    pagescommon.h \
    zlib/zstring.h \
    zlib/zfile.h \
    zlib/database.h \
    zlib/asar.h \
    zlib/SQLite/sqlite3ext.h \
    zlib/SQLite/sqlite3.h \
    global.h \
    websession.h \
    server/logger.h \
    pages/derppage.h \
    pages/errorpage.h

SOURCES += \
    main.cpp \
    server/server.cpp \
    server/request_parser.cpp \
    request_handler.cpp \
    server/reply.cpp \
    server/mime_types.cpp \
    server/connection.cpp \
    pages/homepage.cpp \
    pagescommon.cpp \
    zlib/zstring.cpp \
    zlib/zfile.cpp \
    zlib/database.cpp \
    zlib/asar.tpp \
    zlib/SQLite/sqlite3.c \
    websession.cpp \
    server/logger.cpp \
    lib/system/error_code.cpp \
    pages/derppage.cpp \
    pages/errorpage.cpp

OTHER_FILES += \
    CMakeLists.txt \
    parts/secondary.css \
    parts/main.js \
    parts/main.css \
    parts/jquery.js \
    parts/home.html \
    parts/functions.js
