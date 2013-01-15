TARGET = BoostWebApp
TEMPLATE = app
CONFIG += CONSOLE

INCLUDEPATH += ./include/

HEADERS += \
    server.hpp \
    request_parser.hpp \
    request_handler.hpp \
    request.hpp \
    reply.hpp \
    mime_types.hpp \
    connection.hpp \
    header.hpp

SOURCES += \
    main.cpp \
    server.cpp \
    request_parser.cpp \
    request_handler.cpp \
    reply.cpp \
    mime_types.cpp \
    connection.cpp

OTHER_FILES += \
    CMakeLists.txt
