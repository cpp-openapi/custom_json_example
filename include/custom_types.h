// str replacement for "openapi/runtime/runtime_types.h"
// include before it to override str types

#pragma once

#define OPENAPI_CUSTOM_STRING_TYPES 1

#include <memory>

// string type
namespace openapi 
{

#ifdef OPENAPI_UTF16_STRINGS // user wchar

#define OPENAPI_LITERAL(x) L ## #x
typedef std::shared_ptr<wchar_t[]> string_t;

#else

#define OPENAPI_LITERAL(x) #x

static_assert(false, "not supported yet");
// typedef std::string string_t;

// typedef wchar_t char_t;

#endif // OPENAPI_UTF16_STRINGS

} // namespace openapi