#include "../test.h"
#include "bstd/string.h"
#include "string.h"

test_result test_string_to_uppercase_inplace()
{
    char *cstr = "hello world";
    char *cstr_upper = "HELLO WORLD";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_result string_upper = bstd_string_to_uppercase_inplace(&string.value);

    ASSERT(string_upper.ok);
    ASSERT_STR_EQ(cstr_upper, string.value.data);

    return TEST_OK;
}

test_result test_string_to_uppercase_inplace_null()
{
    char *cstr = "hello world";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_destroy(&string.value);

    bstd_result string_upper = bstd_string_to_uppercase_inplace(&string.value);

    ASSERT_NOT(string_upper.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, string_upper.error);

    return TEST_OK;
}