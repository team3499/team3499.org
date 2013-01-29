#ifndef HTTP_SERVER3_REQUEST_HANDLER_HPP
#define HTTP_SERVER3_REQUEST_HANDLER_HPP

#include <string>
#include <boost/noncopyable.hpp>
#include <boost/thread.hpp>
#include "homepage.h"
#include "zstring.h"

struct Reply;
struct Request;

/// The common handler for all incoming requests.
class RequestHandler : private boost::noncopyable {
public:
  /// Construct with a directory containing files to be served.
  explicit RequestHandler(const std::string& doc_root);

  /// Handle a request and produce a reply.
  void handle_request(Request &req, Reply &rep);

private:
  /// The directory containing the files to be served.
  std::string doc_root_;

  void commandSwitch(Request &req, Reply &rep);

  ZString getReqBody(Request);
  AsArZ getPost(Request);

  /// Perform URL-decoding on a string. Returns false if the encoding was
  /// invalid.
  static bool urlDecode(std::string in, ZString& out);

  void staticFile(Request &req, Reply &rep);
};

#endif // HTTP_SERVER3_REQUEST_HANDLER_HPP
