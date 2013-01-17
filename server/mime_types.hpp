#ifndef HTTP_SERVER3_MIME_TYPES_HPP
#define HTTP_SERVER3_MIME_TYPES_HPP

#include <string>

namespace MimeTypes {

/// Convert a file extension into a MIME type.
std::string extension_to_type(const std::string& extension);

} // namespace mime_types

#endif // HTTP_SERVER3_MIME_TYPES_HPP
