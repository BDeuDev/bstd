#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_ends_with_ok()
{
    const char *cstr = "Hello World";
    const char *q = "ld";
    const char *s = "rld";

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview qs = bstd_strview_new(q);
    bstd_strview ss = bstd_strview_new(s);

    bool s1 = bstd_strview_ends_with(strview, qs);
    bool s2 = bstd_strview_ends_with(strview, ss);

    ASSERT(s1);
    ASSERT(s2);

    return TEST_OK;
}

test_result test_strview_ends_with_failed()
{
    const char *cstr = "Hello World";
    const char *q = "ZU";
    const char *s = "Z";

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview qs = bstd_strview_new(q);
    bstd_strview ss = bstd_strview_new(s);

    bool s1 = bstd_strview_ends_with(strview, qs);
    bool s2 = bstd_strview_ends_with(strview, ss);

    ASSERT_NOT(s1);
    ASSERT_NOT(s2);

    return TEST_OK;
}

test_result test_strview_ends_with_invalid_len()
{
    const char *cstr = "Hello World";
    const char *q = "ddddddddddddddddddddd";
    const char *s = "";

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview qs = bstd_strview_new(q);
    bstd_strview ss = bstd_strview_new(s);

    bool s1 = bstd_strview_ends_with(strview, qs);
    bool s2 = bstd_strview_ends_with(strview, ss);

    ASSERT_NOT(s1);
    ASSERT_NOT(s2);

    return TEST_OK;
}