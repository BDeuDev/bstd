#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_slice()
{
    const char *cstr = "Hello World";
    const char *expected = "llo";
    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_result strview_slice = bstd_strview_slice(strview, 2, 5);

    ASSERT(strview_slice.ok);

    for (size_t i = 0; i < strview_slice.value.length; ++i)
    {
        ASSERT_EQ(expected[i], strview_slice.value.data[i]);
    }

    return TEST_OK;
}

test_result test_strview_slice_invalid_range()
{
    const char *cstr = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_result strview_slice = bstd_strview_slice(strview, 5, 2);

    ASSERT_NOT(strview_slice.ok);

    ASSERT_EQ(BSTD_ERR_OUT_OF_BOUNDS, strview_slice.error);

    return TEST_OK;
}

test_result test_strview_slice_invalid_end_idx()
{
    const char *cstr = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    bstd_strview_result strview_slice = bstd_strview_slice(strview, 2, 100);

    ASSERT_NOT(strview_slice.ok);

    ASSERT_EQ(BSTD_ERR_OUT_OF_BOUNDS, strview_slice.error);

    return TEST_OK;
}
