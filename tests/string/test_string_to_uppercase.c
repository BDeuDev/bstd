#include "../test.h"
#include "bstd/string.h"
#include "string.h"

test_result test_string_to_uppercase()
{
    char *cstr = "hello world";
    char *cstr_upper = "HELLO WORLD";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_result string_upper = bstd_string_to_uppercase(&string.value);

    ASSERT(string_upper.ok);
    ASSERT_STR_EQ(cstr_upper, string_upper.value.data);

    return TEST_OK;
}

test_result test_string_to_uppercase_null()
{
    char *cstr = "hello world";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_destroy(&string.value);

    bstd_string_result string_upper = bstd_string_to_uppercase(&string.value);

    ASSERT_NOT(string_upper.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, string_upper.error);

    return TEST_OK;
}

test_result test_string_to_uppercase_already_upper()
{
    char *cstr = "HELLO WORLD";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_result string_upper = bstd_string_to_uppercase(&string.value);

    ASSERT(string_upper.ok);
    ASSERT_STR_EQ(string.value.data, string_upper.value.data);
    return TEST_OK;
}
