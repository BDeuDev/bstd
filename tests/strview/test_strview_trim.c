#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_trim()
{
    const char *cstr = " Hello World ";
    const char *expected = "Hello World";

    size_t expected_len = strlen(expected);

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_trim(&strview);

    ASSERT_EQ(expected_len, strview.length);
    ASSERT_STR_EQ_WLEN(expected, strview.data, strview.length);

    return TEST_OK;
}

test_result test_strview_trim_multiple()
{
    const char *cstr = "    Hello World    ";
    const char *expected = "Hello World";

    size_t expected_len = strlen(expected);

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_trim(&strview);

    ASSERT_EQ(expected_len, strview.length);
    ASSERT_STR_EQ_WLEN(expected, strview.data, strview.length);

    return TEST_OK;
}