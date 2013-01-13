## BoostWebApp CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(BoostWebApp)
FIND_PACKAGE(Boost COMPONENTS system filesystem REQUIRED)
SET(BOOST_LIBRARYDIR /usr/lib/boost)
SET(BOOST_INCLUDEDIR /usr/include/boost)

SET(CMAKE_GENERATOR "Unix Makefiles")

SET(BoostWebApp_HEADERS ### =================== HEADERS =================== ###
    server.hpp
    request_parser.hpp
    request_handler.hpp
    request.hpp
    reply.hpp
    mime_types.hpp
    connection.hpp
    header.hpp
)

SET(BoostWebApp_SOURCES ### =================== SOURCES =================== ###
    main.cpp
    server.cpp
    request_parser.cpp
    request_handler.cpp
    reply.cpp
    mime_types.cpp
    connection.cpp
)

INCLUDE_DIRECTORIES(
    .
    ../Boost_Source
    ../Boost_Source/boost
)

#ADD_DEFINITIONS(-L../Boost_Source/bin.v2/libs/system/build/gcc-4.6.1/release/link-static/threading-multi)
#ADD_DEFINITIONS(-lboost_system)
#ADD_DEFINITIONS(-L/home/chaos/Projects/Boost_Source/stage/lib)
#ADD_DEFINITIONS(-lboost_systems)
#ADD_DEFINITIONS(-lboost_thread)
#ADD_DEFINITIONS(-lpthread)

ADD_EXECUTABLE(webapp ${BoostWebApp_SOURCES})
TARGET_LINK_LIBRARIES(webapp ${Boost_SYSTEM_LIBRARY})
