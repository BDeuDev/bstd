#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_split_lines()
{
    const char *cstr = "Hello World\nHello World\nHello World";

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_split_iter iter = bstd_strview_split_lines(&strview);

    ASSERT_STR_EQ(iter.source.data, strview.data);
    ASSERT_STR_EQ("\n", iter.qry.data);
    ASSERT_EQ(0, iter.current_index);

    return TEST_OK;
}