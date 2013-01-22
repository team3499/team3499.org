## BoostWebApp CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_GENERATOR "Unix Makefiles")

PROJECT(BoostWebApp)

FIND_PACKAGE(Qt4 REQUIRED)
SET(QT_DONT_USE_QTGUI TRUE)

SET(BoostWebApp_HEADERS ### =================== HEADERS =================== ###
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
    pages/homepage.h
    pages/derppage.h
    pages/errorpage.h
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
    pages/homepage.cpp
    pages/derppage.cpp
    pages/errorpage.cpp
# Zennix Libs
    #zlib/asar.tpp
    #zlib/database.cpp
    zlib/zfile.cpp
    zlib/zstring.cpp
    #zlib/SQLite/sqlite3.c
# Boost
    lib/system/error_code.cpp
)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(
    /usr/include
    /usr/include/boost
    #lib/include
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

#ADD_DEFINITIONS(-D ZFILE_USE_QT)
ADD_DEFINITIONS(-D ZSTRING_USE_QT)

ADD_DEFINITIONS(-g -pthread)
#ADD_DEFINITIONS(-O3)

LINK_DIRECTORIES(/usr/lib/boost /usr/include/boost/boost/stage/lib /usr/include/boost/stage/lib)
ADD_EXECUTABLE(webapp ${BoostWebApp_SOURCES})
TARGET_LINK_LIBRARIES(webapp ${QT_LIBRARIES} boost_thread)

ADD_DEPENDENCIES(webapp resources)
