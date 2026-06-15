#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_split_once()
{
    const char *cstr = "Hello_World";
    const char *cquery = "_";
    const char *left = "Hello";
    const char *right = "World";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview strview_query = bstd_strview_new(cquery);

    bstd_strview_split_once_result result = bstd_strview_split_once(&strview, strview_query);

    ASSERT_EQ(strlen(left), result.left.length);
    ASSERT_EQ(strlen(right), result.left.length);
    ASSERT_STR_EQ_WLEN(left, result.left.data, strlen(left));
    ASSERT_STR_EQ_WLEN(right, result.right.data, strlen(right));

    return TEST_OK;
}