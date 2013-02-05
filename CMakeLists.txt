## 3499App CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_GENERATOR "Unix Makefiles")

PROJECT(BoostWebApp)

SET(QT_DONT_USE_QTGUI TRUE)
FIND_PACKAGE(Qt4 REQUIRED)

SET(BOOST_LIBRARYDIR /usr/lib/boost) # Set this to the location of your Boost Library Binaries
SET(Boost_USE_STATIC_LIBS ON)
FIND_PACKAGE(Boost COMPONENTS thread REQUIRED)

### !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! README !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ###
# BoostWebApp should build on any Unix/Linux platform.
# This app uses CMake to generate makefiles. Do NOT build this with Qmake, it will fail.
# The Qmake project file is used to tell the IDE (QtCreator) how to parse the project, so AutoCompletion works correctly.
# If you are using QtCreator, open the Qmake project file with QtCreator, and change the build commands to CMake.
# Typical Debug Command: (run in build directory) cmake -DDEBUG=1 <source_directory>
# Typical Debug Command: (run in build directory) cmake -DRELEASE=1 <source_directory>
#
# You must have the Boost and Qt Libraries and Header Files installed correctly to build this application.
#
# To run BoostWebApp correctly, some command-line arguments are required.
# ./(build_dir)/webapp <address-to-bind> <port> <thread-pool-size> <document-root>
# Typical Development Run Command: $ ./webapp 0.0.0.0 8080 10 docroot
# You need to be root to run on port 80, so:
# Typical Release Deployment: # ./webapp 0.0.0.0 80 10 docroot
### !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ###

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
# Commands
    commands/user.h
    commands/userdata.h
# Pages
    pages/aboutpage.h
    pages/devpages.h
    pages/errorpage.h
    pages/gallerypage.h
    pages/helppage.h
    pages/homepage.h
    pages/pagebase.h
    pages/pages.h
    pages/raytracepages.h
# Zennix Libs
    zlib/asar.h
    zlib/database.h
    zlib/zfile.h
    zlib/zstring.h
    zlib/sqlite3.h
)

SET(BoostWebApp_SOURCES ### =================== SOURCES =================== ###
    main.cpp
    pagescommon.cpp
    request_handler.cpp
    request_switch.cpp
    staticfile.cpp
    websession.cpp
# Server
    server/connection.cpp
    server/logger.cpp
    server/mime_types.cpp
    server/reply.cpp
    server/request_parser.cpp
    server/server.cpp
# Commands
    commands/user.cpp
# Pages
    pages/aboutpage.cpp
    pages/devpages.cpp
    pages/errorpage.cpp
    pages/gallerypage.cpp
    pages/helppage.cpp
    pages/homepage.cpp
    pages/pagebase.cpp
    pages/raytracepage.cpp
# Zennix Libs
    #zlib/asar.tpp
    zlib/database.cpp
    zlib/zfile.cpp
    zlib/zstring.cpp
    zlib/sqlite3.c
# Boost
    lib/system/error_code.cpp
)

INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

INCLUDE_DIRECTORIES(
    ${CMAKE_BINARY_DIR}
    ./
    server/
    commands/
    pages/
    zlib/
    zlib/SQLite/
)

### =================== CONFIG =================== ###

EXECUTE_PROCESS(COMMAND date OUTPUT_VARIABLE MAKE_BUILD_TIME)
STRING(STRIP ${MAKE_BUILD_TIME} MAKE_BUILD_TIME)
CONFIGURE_FILE(generated.h gen.h @ONLY)

ADD_CUSTOM_TARGET(resources
    COMMAND echo Refreshing Resources ...
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/docroot
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/sessions
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/logs
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/parts
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/db
    COMMAND cp -R ${CMAKE_SOURCE_DIR}/docroot ${CMAKE_BINARY_DIR}/docroot
    COMMAND cp -R ${CMAKE_SOURCE_DIR}/parts ${CMAKE_BINARY_DIR}/parts
    COMMAND mkdir ${CMAKE_BINARY_DIR}/sessions
    COMMAND mkdir ${CMAKE_BINARY_DIR}/logs
    COMMAND mkdir ${CMAKE_BINARY_DIR}/db
    COMMAND echo Done.
)

### =================== BUILD =================== ###

ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DHAS_BOOST)

# Required - Resolves some conditions that change during build
ADD_DEFINITIONS(-D BUILDING)

# Used for QDateTime
ADD_DEFINITIONS(-D ZSTRING_USE_QT)
#ADD_DEFINITIONS(-D ZFILE_USE_QT)

IF(DEBUG)
    ADD_DEFINITIONS(-g)
    ADD_CUSTOM_TARGET(building
        COMMAND echo Debug Build Starting...
    )
ELSEIF(RELEASE)
    ADD_DEFINITIONS(-O3)
    ADD_CUSTOM_TARGET(building
        COMMAND echo Release Build Starting...
    )
ELSE()
    ADD_CUSTOM_TARGET(building
        COMMAND echo Normal Build Starting...
    )
ENDIF()

ADD_DEFINITIONS(-pthread)
ADD_EXECUTABLE(webapp ${BoostWebApp_SOURCES})
TARGET_LINK_LIBRARIES(webapp ${QT_LIBRARIES} ${Boost_THREAD_LIBRARY})

ADD_CUSTOM_COMMAND(TARGET webapp POST_BUILD
    COMMAND ./webapp db
)

ADD_DEPENDENCIES(webapp building)
ADD_DEPENDENCIES(building resources)
