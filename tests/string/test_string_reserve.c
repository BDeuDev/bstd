#include "../test.h"
#include "bstd/string.h"

test_result test_string_reserve()
{
    char *cstr = "Hello World";

    bstd_string_result string = bstd_string_new(cstr);

    bstd_result reserve = bstd_string_reserve(&string.value, 30);

    ASSERT(reserve.ok);
    ASSERT_EQ(30, string.value.capacity);
    ASSERT_STR_EQ(cstr, string.value.data);

    return TEST_OK;
}