#include "gtest/gtest.h"

#include "njson.h"
typedef CJson Json;

TEST(Json, Serialize)
{

    Json x;
    x.Parse(openapi::StringT(R"(
        {
            "str" : "str_val",
            "int" : 1
        }
    )"));

    ASSERT_EQ(1, x.GetMember<int>(openapi::StringT("int")));
    ASSERT_STREQ(openapi::StringT("str_val").get(), x.GetMember<openapi::string_t>(openapi::StringT("str")).get());

}