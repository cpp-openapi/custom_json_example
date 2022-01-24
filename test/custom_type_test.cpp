#include "gtest/gtest.h"
#include "custom_types.h"
#include "custom_strconv.h"
#include "openapi/runtime/runtime_types.h"

#include <cstring>

TEST(String, Init)
{
    openapi::string_t x(new wchar_t[10]);
    //openapi::string_t x = std::make_shared<wchar_t[]>(10);
    //std::memcpy(x.get(), L"hello", sizeof(L"hello"));
    wcsncpy(x.get(), L"hello", 6);
    x.get()[5] = L'\0';
    ASSERT_STREQ(L"hello", x.get());
}

TEST(String, ConvertFromChar)
{
    openapi::string_t x = openapi::StringT("hello");
    ASSERT_STREQ(L"hello", x.get());

    openapi::string_t y = openapi::StringT("");
    ASSERT_STREQ(L"", y.get());
}

TEST(String, ConvertToStdStr)
{
    openapi::string_t x = openapi::StringT("hello");
    std::string xx = openapi::ToStdString(x);
    ASSERT_STREQ("hello", xx.c_str());

    openapi::string_t y = openapi::StringT("");
    std::string yy = openapi::ToStdString(y);
    ASSERT_STREQ("", yy.c_str());
}