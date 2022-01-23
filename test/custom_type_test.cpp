#include "gtest/gtest.h"
#include "custom_types.h"
#include "custom_strconv.h"
#include "openapi/runtime/runtime_types.h"

TEST(String, Init)
{
    openapi::string_t x = std::make_shared<wchar_t[]>(10);
    std::memcpy(x.get(), L"hello", sizeof(L"hello"));
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