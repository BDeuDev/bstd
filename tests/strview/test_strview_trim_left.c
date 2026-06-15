#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_trim_left()
{
    const char *cstr = " Hello World ";
    const char *expected = "Hello World ";

    size_t expected_len = strlen(expected);

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_trim_left(&strview);

    ASSERT_STR_EQ(expected, strview.data);
    ASSERT_EQ(expected_len, strview.length);

    return TEST_OK;
}

test_result test_strview_trim_left_multiple()
{
    const char *cstr = "      Hello World ";
    const char *expected = "Hello World ";

    size_t expected_len = strlen(expected);

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_trim_left(&strview);

    ASSERT_STR_EQ(expected, strview.data);
    ASSERT_EQ(expected_len, strview.length);

    return TEST_OK;
}
