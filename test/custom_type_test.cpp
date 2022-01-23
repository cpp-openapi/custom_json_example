#include "gtest/gtest.h"
#include "custom_types.h"
#include "openapi/runtime/runtime_types.h"

TEST(String, Init)
{
    openapi::string_t x = std::make_shared<wchar_t[]>(10);
    std::memcpy(x.get(), L"hello", sizeof(L"hello"));
    ASSERT_STREQ(L"hello", x.get());
}