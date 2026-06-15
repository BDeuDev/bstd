#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_split()
{
    const char *cstr = "Hello World";
    const char *cquery = " ";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview strview_query = bstd_strview_new(cquery);

    bstd_strview_split_iter iter = bstd_strview_split(&strview, strview_query);

    ASSERT_STR_EQ(iter.source.data, strview.data);
    ASSERT_STR_EQ(iter.qry.data, strview_query.data);
    ASSERT_EQ(0, iter.current_index);

    return TEST_OK;
}