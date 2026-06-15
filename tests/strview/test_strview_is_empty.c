#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_is_empty()
{
    const char *cstr = "";

    bstd_strview strview = bstd_strview_new(cstr);

    bool result = bstd_strview_is_empty(strview);

    ASSERT(result);

    return TEST_OK;
}

test_result test_strview_is_empty_withspaces()
{
    const char *cstr = "     ";

    bstd_strview strview = bstd_strview_new(cstr);

    bool result = bstd_strview_is_empty(strview);

    ASSERT(result);

    return TEST_OK;
}

test_result test_strview_is_not_empty()
{
    const char *cstr = " Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    bool result = bstd_strview_is_empty(strview);

    ASSERT_NOT(result);

    return TEST_OK;
}