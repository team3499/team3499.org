#include "request_handler.hpp"
#include "mime_types.hpp"


void RequestHandler::staticFile(Request &req, Reply &rep){
    std::string request_path = req.rawpath.str();
    /*if (!urlDecode(req.uri, request_path)){
        rep = Reply::stock_reply(Reply::bad_request);
        return;
    }*/

    // Request path must be absolute and not contain "..".
    if (request_path.empty() || request_path[0] != '/' || request_path.find("..") != std::string::npos){
        rep = Reply::stock_reply(Reply::bad_request);
        return;
    }

    // If path ends in slash (i.e. is a directory) then add "index.html".
    if (request_path[request_path.size() - 1] == '/'){
        request_path += "index.html";
    }

    // Determine the file extension.
    std::size_t last_slash_pos = request_path.find_last_of("/");
    std::size_t last_dot_pos = request_path.find_last_of(".");
    std::string extension;
    if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos){
        extension = request_path.substr(last_dot_pos + 1);
    }

    ZFile staticfl;
    if(!staticfl.open(doc_root_ + request_path)){
        rep = Reply::stock_reply(Reply::not_found);
        return;
    }
    rep.status = Reply::ok;
    rep.content = staticfl.read();
    rep.headers["Content-Length"] = rep.content.length();
    rep.headers["Content-Type"] = MimeTypes::extension_to_type(extension);
    rep.headers["Cache-Control"] = "max-age=3600, must-revalidate";
}
