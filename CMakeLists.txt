## BoostWebApp CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_GENERATOR "Unix Makefiles")

PROJECT(BoostWebApp)

FIND_PACKAGE(Qt4 REQUIRED)
SET(QT_DONT_USE_QTGUI TRUE)

SET(BoostWebApp_HEADERS ### =================== HEADERS =================== ###
    generated.h
    global.h
    pagescommin.h
    request_handler.hpp
    websession.h
# Server
    server/connection.hpp
    server/logger.h
    server/mime_types.hpp
    server/reply.hpp
    server/request.hpp
    server/request_parser.hpp
    server/server.hpp
# Pages
    pages/aboutpage.h
    pages/devpages.h
    pages/errorpage.h
    pages/helppage.h
    pages/homepage.h
    pages/pagebase.h
    pages/pages.h
# Zennix Libs
    zlib/asar.h
    #zlib/database.h
    zlib/zfile.h
    zlib/zstring.h
    #zlib/SQLite/sqlite3.h
    #zlib/SQLite/sqlite3ext.h
)

SET(BoostWebApp_SOURCES ### =================== SOURCES =================== ###
    main.cpp
    request_handler.cpp
    websession.cpp
    pagescommon.cpp
# Server
    server/connection.cpp
    server/logger.cpp
    server/mime_types.cpp
    server/reply.cpp
    server/request_parser.cpp
    server/server.cpp
# Pages
    pages/aboutpage.cpp
    pages/devpages.cpp
    pages/errorpage.cpp
    pages/helppage.cpp
    pages/homepage.cpp
    pages/raytracepage.cpp
# Zennix Libs
    #zlib/asar.tpp
    #zlib/database.cpp
    zlib/zfile.cpp
    zlib/zstring.cpp
    #zlib/SQLite/sqlite3.c
# Boost
    lib/system/error_code.cpp
)

SET(BoostWebApp_RESOURCES resource.qrc)

### =================== CONFIG =================== ###

EXECUTE_PROCESS(COMMAND date OUTPUT_VARIABLE MAKE_BUILD_TIME)
STRING(STRIP ${MAKE_BUILD_TIME} MAKE_BUILD_TIME)
CONFIGURE_FILE(generated.h gen.h @ONLY)

INCLUDE(${QT_USE_FILE})

INCLUDE_DIRECTORIES(
    /usr/include
    #lib/include
    ${CMAKE_BINARY_DIR}
    ./
    server/
    pages/
    zlib/
    zlib/SQLite/
)

ADD_CUSTOM_TARGET(resources
    COMMAND echo Refreshing Resources ...
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/docroot
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/sessions
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/logs
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/parts
    COMMAND cp -R ${CMAKE_SOURCE_DIR}/docroot ${CMAKE_BINARY_DIR}/docroot
    COMMAND cp -R ${CMAKE_SOURCE_DIR}/parts ${CMAKE_BINARY_DIR}/parts
    COMMAND mkdir ${CMAKE_BINARY_DIR}/sessions
    COMMAND mkdir ${CMAKE_BINARY_DIR}/logs
    COMMAND echo Done.
)

### =================== BUILD =================== ###

ADD_DEFINITIONS(${QT_DEFINITIONS})

# Required - Supresses false IDE warning
ADD_DEFINITIONS(-D BUILDING)

#ADD_DEFINITIONS(-D ZFILE_USE_QT)

# Used for QDateTime
ADD_DEFINITIONS(-D ZSTRING_USE_QT)

ADD_DEFINITIONS(-g -pthread)
#ADD_DEFINITIONS(-O3)

LINK_DIRECTORIES(
    /usr/lib/boost
    /usr/include/boost/stage/lib
)

QT4_ADD_RESOURCES(BoostApp_RC_SRCS ${BoostApp_RESOURCES})

ADD_EXECUTABLE(webapp ${BoostWebApp_SOURCES} ${BoostApp_RC_SRCS})
TARGET_LINK_LIBRARIES(webapp ${QT_LIBRARIES} libboost_thread.a)
#TARGET_LINK_LIBRARIES(webapp boost_thread)

ADD_DEPENDENCIES(webapp resources)
