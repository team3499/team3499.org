## BoostWebApp CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(BoostWebApp)

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

ADD_CUSTOM_TARGET(resources
    COMMAND echo Refreshing Resources ...
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/docroot
    COMMAND cp -R ${CMAKE_SOURCE_DIR}/docroot ${CMAKE_BINARY_DIR}/docroot
    COMMAND echo Done.
)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/libs)
ADD_EXECUTABLE(webapp ${BoostWebApp_SOURCES})
TARGET_LINK_LIBRARIES(webapp boost_system boost_thread)
ADD_DEPENDENCIES(webapp resources)
