#include "../test.h"
#include "bstd/string.h"
#include "string.h"

test_result test_string_slice()
{
    char *cstr = "Hello world";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_result string_slice = bstd_string_slice(&string.value, 2, 4);

    ASSERT(string_slice.ok);

    return TEST_OK;
}

test_result test_string_slice_invalid_range()
{
    char *cstr = "Hello world";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_result string_slice_1 = bstd_string_slice(&string.value, 4, 2);

    ASSERT_NOT(string_slice_1.ok);
    ASSERT_EQ(BSTD_ERR_OUT_OF_BOUNDS, string_slice_1.error);

    bstd_string_result string_slice_2 = bstd_string_slice(&string.value, 2, 100);

    ASSERT_NOT(string_slice_2.ok);
    ASSERT_EQ(BSTD_ERR_OUT_OF_BOUNDS, string_slice_2.error);

    return TEST_OK;
}