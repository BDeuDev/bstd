#include "../test.h"
#include "bstd/string.h"

test_result test_string_clone()
{
    char *cstr = "Hello world";
    bstd_string_result string = bstd_string_new(cstr);
    bstd_string_result string_clone = bstd_string_clone(&string.value);

    ASSERT(string_clone.ok);
    ASSERT_NOT_EQ(&string.value.data, &string_clone.value.data);

    return TEST_OK;
}

test_result test_string_clone_capacity()
{
    char *cstr = "Hello world";
    bstd_string_result string = bstd_string_new(cstr);
    bstd_string_result string_clone = bstd_string_clone(&string.value);

    ASSERT(string_clone.ok);
    ASSERT_EQ(string.value.capacity, string_clone.value.capacity);

    return TEST_OK;
}

test_result test_string_clone_lenght()
{
    char *cstr = "Hello world";
    bstd_string_result string = bstd_string_new(cstr);
    bstd_string_result string_clone = bstd_string_clone(&string.value);

    ASSERT(string_clone.ok);
    ASSERT_EQ(string.value.length, string_clone.value.length);

    return TEST_OK;
}
