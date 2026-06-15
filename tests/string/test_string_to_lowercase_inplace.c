#include "../test.h"
#include "bstd/string.h"
#include "string.h"

test_result test_string_to_lowercase_inplace()
{
    char *cstr = "HELLO WORLD";
    char *cstr_lower = "hello world";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_result string_lower = bstd_string_to_lowercase_inplace(&string.value);

    ASSERT(string_lower.ok);
    ASSERT_STR_EQ(cstr_lower, string.value.data);

    return TEST_OK;
}

test_result test_string_to_lowercase_inplace_null()
{
    char *cstr = "HELLO WORLD";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_destroy(&string.value);

    bstd_result string_upper = bstd_string_to_lowercase_inplace(&string.value);

    ASSERT_NOT(string_upper.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, string_upper.error);

    return TEST_OK;
}