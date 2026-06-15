#include "../test.h"
#include "bstd/string.h"
#include "string.h"

#define STRING_EMPTY_CAP 8
#define STRING_EMPTY_LEN 0

test_result test_string_new()
{
    char *cstr = "Hello world";
    size_t len = strlen(cstr);
    size_t cap = len > 0 ? len * 2 : 8;

    bstd_string_result string = bstd_string_new(cstr);

    ASSERT(string.ok);
    ASSERT_STR_EQ(cstr, string.value.data);
    ASSERT_EQ(len, string.value.length);
    ASSERT_EQ(cap, string.value.capacity);

    return TEST_OK;
}

test_result test_string_new_length()
{
    char *cstr = "Hello world";
    size_t len = strlen(cstr);

    bstd_string_result string = bstd_string_new(cstr);

    ASSERT_EQ(len, string.value.length);

    return TEST_OK;
}

test_result test_string_new_capacity()
{
    char *cstr = "Hello world";
    size_t len = strlen(cstr);
    size_t cap = len > 0 ? len * 2 : 8;

    bstd_string_result string = bstd_string_new(cstr);

    ASSERT_EQ(cap, string.value.capacity);

    return TEST_OK;
}

test_result test_string_new_deep_copy()
{
    char buffer[] = "Hello world";

    bstd_string_result string = bstd_string_new(buffer);

    buffer[0] = 'X';

    ASSERT_STR_EQ("Hello world", string.value.data);

    return TEST_OK;
}

test_result test_string_new_null_terminated()
{
    bstd_string_result string = bstd_string_new("abc");

    ASSERT_EQ('\0', string.value.data[string.value.length]);

    return TEST_OK;
}

test_result test_string_new_null()
{
    bstd_string_result string = bstd_string_new(NULL);

    ASSERT(!string.ok);

    ASSERT_EQ(BSTD_ERR_INVALID_ARG, string.error);

    return TEST_OK;
}

test_result test_string_new_empty()
{
    bstd_string_result string = bstd_string_new("");

    ASSERT(string.ok);
    ASSERT_EQ(STRING_EMPTY_CAP, string.value.capacity);
    ASSERT_EQ(STRING_EMPTY_LEN, string.value.length);
    ASSERT_STR_EQ("\0", string.value.data);

    return TEST_OK;
}