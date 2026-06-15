#include "../test.h"
#include "bstd/string.h"

test_result test_string_shrink_to_fit()
{
    char *cstr = "Hello World";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_result shrink = bstd_string_shrink_to_fit(&string.value);

    ASSERT(shrink.ok);
    ASSERT_STR_EQ(cstr, string.value.data);
    ASSERT_EQ(string.value.length, string.value.capacity);

    return TEST_OK;
}