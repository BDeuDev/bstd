#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_equals()
{
    const char *cstr = "Hello World";
    const char *compare = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview strview_compare = bstd_strview_new(compare);

    bool equals = bstd_strview_equals(strview, strview_compare);

    ASSERT(equals);

    return TEST_OK;
}

test_result test_strview_equals_failed()
{
    const char *cstr = "Hello World";
    const char *compare = "Hello worldd";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview strview_compare = bstd_strview_new(compare);

    bool equals = bstd_strview_equals(strview, strview_compare);

    ASSERT_NOT(equals);

    return TEST_OK;
}