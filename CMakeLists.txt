## BoostWebApp CMakeLists.txt
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(BoostWebApp)

IF(UNIX)
SET(CMAKE_GENERATOR "Unix Makefiles")
ELSE()
SET(CMAKE_GENERATOR "MinGW Makefiles")
ENDIF()

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
    lib/system/error_code.cpp
#    lib/thread/future.cpp
#    lib/thread/tss_null.cpp
#    lib/thread/win32/thread.cpp
#    lib/thread/win32/tss_dll.cpp
#    lib/thread/win32/tss_pe.cpp
#    lib/thread/pthread/once.cpp
#    lib/thread/pthread/thread.cpp
)

INCLUDE_DIRECTORIES(
    .
    lib/include
    lib/system
)

ADD_CUSTOM_TARGET(resources
    COMMAND echo Refreshing Resources ...
    COMMAND rm -Rf ${CMAKE_BINARY_DIR}/docroot
    COMMAND cp -R ${CMAKE_SOURCE_DIR}/docroot ${CMAKE_BINARY_DIR}/docroot
    COMMAND echo Done.
)

ADD_DEFINITIONS(-D_WIN32_WINNT=0x0501)
#ADD_DEFINITIONS(-D BOOST_ALL_DYN_LINK)
ADD_DEFINITIONS(-D BOOST_ALL_NO_LIB)

IF(UNIX)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/unix)
ELSE()
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/win32)
ENDIF()

ADD_EXECUTABLE(webapp ${BoostWebApp_SOURCES})

IF(UNIX)
TARGET_LINK_LIBRARIES(webapp boost_system boost_thread)
ELSE()
#TARGET_LINK_LIBRARIES(webapp boost_system boost_thread wsock32 ws2_32)
TARGET_LINK_LIBRARIES(webapp boost_thread wsock32 ws2_32)
ENDIF()

ADD_DEPENDENCIES(webapp resources)
