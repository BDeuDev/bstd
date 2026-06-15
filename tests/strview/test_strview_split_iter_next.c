#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_split_iter_next()
{
    const char *cstr = "Hello World";
    const char *cquery = " ";
    const char *left = "Hello";
    const char *right = "World";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview strview_query = bstd_strview_new(cquery);

    bstd_strview_split_iter iter = bstd_strview_split(&strview, strview_query);

    bstd_strview l = bstd_strview_split_iter_next(&iter);

    ASSERT_EQ(strlen(left), l.length);
    ASSERT_STR_EQ_WLEN(left, l.data, strlen(left));

    bstd_strview r = bstd_strview_split_iter_next(&iter);

    ASSERT_EQ(strlen(right), r.length);
    ASSERT_STR_EQ_WLEN(right, r.data, strlen(right));

    return TEST_OK;
}

test_result test_strview_split_lines_iter_next()
{
    const char *cstr = "Hello World\nBye World\nHello World";
    const char *one = "Hello World";
    const char *two = "Bye World";
    const char *three = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_split_iter iter = bstd_strview_split_lines(&strview);

    bstd_strview o = bstd_strview_split_iter_next(&iter);

    ASSERT_EQ(strlen(one), o.length);

    bstd_strview tw = bstd_strview_split_iter_next(&iter);

    ASSERT_EQ(strlen(two), tw.length);

    bstd_strview th = bstd_strview_split_iter_next(&iter);

    ASSERT_EQ(strlen(three), th.length);

    return TEST_OK;
}