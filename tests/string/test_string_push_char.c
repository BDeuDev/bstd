#include "../test.h"
#include "bstd/string.h"

test_result test_string_push_char()
{
    char *cstr = "Hello World";
    char c = 'C';
    char *expected = "Hello WorldC";

    bstd_string_result string = bstd_string_new(cstr);
    bstd_result string_push = bstd_string_push_char(&string.value, c);

    ASSERT(string_push.ok);
    ASSERT_STR_EQ(expected, string.value.data);

    return TEST_OK;
}

test_result test_string_push_char_null()
{
    char *cstr = "Hello World";
    char c = 'C';

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_destroy(&string.value);

    bstd_result string_push = bstd_string_push_char(&string.value, c);

    ASSERT_NOT(string_push.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, string_push.error);

    return TEST_OK;
}
