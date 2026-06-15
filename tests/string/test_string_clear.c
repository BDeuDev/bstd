#include "../test.h"
#include "bstd/string.h"

test_result test_string_clear()
{
    char *cstr = "Hello World";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_clear(&string.value);

    ASSERT_EQ(0, string.value.length);
    ASSERT_EQ(22, string.value.capacity);
    ASSERT_STR_EQ("", string.value.data);

    return TEST_OK;
}