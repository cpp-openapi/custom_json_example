#include "njson.h"

bool CJson::HasKey(const openapi::string_t &key) const
{
    return this->_j.contains(openapi::ToStdString(key)); // TODO: wchar to char
}

// OPENAPI macro requires this
// bool CJson::HasKey(const char* key) const
// {
//     return this->_j.contains(key);
// }

void CJson::Parse(const openapi::string_t &data)
{
    this->_j = nlohmann::json::parse(openapi::ToStdString(data));
}

openapi::string_t CJson::ToString() const
{
    return openapi::StringT(this->_j.dump().c_str());
}