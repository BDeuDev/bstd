#include "../test.h"
#include "bstd/string.h"

test_result test_string_destroy()
{
    char *cstr = "Hello World";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_string_destroy(&string.value);

    ASSERT_EQ(NULL, string.value.data);
    ASSERT_EQ(0, string.value.length);
    ASSERT_EQ(0, string.value.capacity);

    return TEST_OK;
}