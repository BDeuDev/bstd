#include "bstd/string.h"

#include "../test.h"
#include "string.h"

test_result test_string_to_lowercase()
{
    char *cstr = "HELLO WORLD";
    char *cstr_lower = "hello world";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_result string_lower = bstd_string_to_lowercase(&string.value);

    ASSERT(string_lower.ok);
    ASSERT_STR_EQ(cstr_lower, string_lower.value.data);

    return TEST_OK;
}

test_result test_string_to_lowercase_null()
{
    char *cstr = "HELLO WORLD";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_destroy(&string.value);

    bstd_string_result string_lower = bstd_string_to_lowercase(&string.value);

    ASSERT_NOT(string_lower.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, string_lower.error);

    return TEST_OK;
}

test_result test_string_to_lowercase_already_lower()
{
    char *cstr = "hello world";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_result string_lower = bstd_string_to_lowercase(&string.value);

    ASSERT(string_lower.ok);
    ASSERT_STR_EQ(string.value.data, string_lower.value.data);
    return TEST_OK;
}
