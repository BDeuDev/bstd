#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_new()
{
    const char *cstr = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    ASSERT_STR_EQ(cstr, strview.data);
    ASSERT_EQ(strlen(cstr), strview.length);

    return TEST_OK;
}