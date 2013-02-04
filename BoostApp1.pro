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
    websession.h \
    server/logger.h \
    pages/errorpage.h \
    pages/aboutpage.h \
    global.h \
    generated.h \
    pages/helppage.h \
    pages/pages.h \
    pages/devpages.h \
    pages/pagebase.h \
    pages/raytracepage.h \
    zlib/sqlite3.h \
    commands/user.h \
    commands/userdata.h

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
    pages/errorpage.cpp \
    pages/aboutpage.cpp \
    pages/helppage.cpp \
    pages/devpages.cpp \
    pages/raytracepage.cpp \
    zlib/sqlite3.c \
    commands/user.cpp \
    pages/pagebase.cpp \
    staticfile.cpp \
    request_switch.cpp

OTHER_FILES += \
    CMakeLists.txt \
    parts/secondary.css \
    parts/main.js \
    parts/main.css \
    parts/jquery.js \
    parts/functions.js \
    parts/main.html \
    parts/pages/home.html \
    parts/pages/about.html \
    parts/pages/derp.html \
    parts/pages/help.html \
    parts/pages/dump.html \
    parts/pages/raytrace.html \
    parts/pages/helpcom.html \
    parts/pages/errors/missing.html \
    parts/pages/errors/bad_request.html \
    parts/commands/login-0.html \
    parts/pages/me.html \
    parts/commands/login-2.html \
    parts/commands/login-1.html \
    parts/commands/logout.html \
    parts/common/header.html

RESOURCES +=
