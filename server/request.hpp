#ifndef HTTP_SERVER3_REQUEST_HPP
#define HTTP_SERVER3_REQUEST_HPP

#include <string>
#include <vector>
#include "websession.h"

/// A request received from a client.
class Request {
public:
    std::string method;
    std::string uri;
    int http_version_major;
    int http_version_minor;
    std::string raw_request;
    std::string raw_headers;
    ZString reqbody;
    AsArZ headers;
    bool ispost;
    AsArZ postvars;
    WebSession sess;
    ZString rawpath;
    ZString rawcommand;
    AsArZ path;
    AsArZ comm;
    bool ajax;
};


#endif // HTTP_SERVER3_REQUEST_HPP
