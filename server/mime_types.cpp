#include "mime_types.hpp"

namespace MimeTypes {

struct Mapping {
    const char* extension;
    const char* mime_type;
} mappings[] =
{
    { "gif", "image/gif" },
    { "htm", "text/html" },
    { "html", "text/html" },
    { "jpg", "image/jpeg" },
    { "png", "image/png" },
    { "js", "text/javascript" },
    { "css", "text/css" },
    { "otf", "font/opentype" },
    { 0, 0 } // Marks end of list.
};

std::string extension_to_type(const std::string& extension){
    for(Mapping* m = mappings; m->extension; ++m){
        if(m->extension == extension){
            return m->mime_type;
        }
    }
    return "text/plain";
}

} // namespace mime_types
