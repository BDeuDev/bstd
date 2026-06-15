#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_advance()
{
    const char *cstr = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    char c = strview.data[2];

    bool result = bstd_strview_advance(&strview, 3);

    ASSERT(result);
    ASSERT_EQ(c, strview.data[0]);

    return TEST_OK;
}

test_result test_strview_advance_empty()
{
    const char *cstr = "";

    bstd_strview strview = bstd_strview_new(cstr);

    bool result = bstd_strview_advance(&strview, 3);

    ASSERT_NOT(result);

    return TEST_OK;
}

test_result test_strview_advance_null()
{
    const char *cstr = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    strview.data = NULL;

    bool result = bstd_strview_advance(&strview, 3);

    ASSERT_NOT(result);

    return TEST_OK;
}