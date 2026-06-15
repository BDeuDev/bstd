#include "../test.h"
#include "bstd/string.h"

test_result test_string_reverse()
{
    char *cstr = "Hello world";
    char *cstr_reverse = "dlrow olleH";
    bstd_string_result string = bstd_string_new(cstr);
    bstd_string_result string_reverse = bstd_string_reverse(string.value);

    ASSERT(string_reverse.ok);
    ASSERT_NOT_EQ(string.value.data, string_reverse.value.data);
    ASSERT_STR_EQ(cstr_reverse, string_reverse.value.data);

    return TEST_OK;
}

test_result test_string_reverse_null()
{
    char *cstr = "Hello world";
    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_destroy(&string.value);

    bstd_string_result string_reverse = bstd_string_reverse(string.value);

    ASSERT_NOT(string_reverse.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, string_reverse.error);

    return TEST_OK;
}
