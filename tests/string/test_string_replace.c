#include "../test.h"
#include "bstd/string.h"

test_result test_string_replace_basic()
{
    bstd_string_result string = bstd_string_new("Hello World");

    bstd_result result = bstd_string_replace(&string.value, "World", "BSTD");

    ASSERT(result.ok);
    ASSERT_STR_EQ("Hello BSTD", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_longer()
{
    bstd_string_result string = bstd_string_new("Hello World");

    bstd_result result = bstd_string_replace(&string.value, "World", "Wonderful World");

    ASSERT(result.ok);
    ASSERT_STR_EQ("Hello Wonderful World", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_shorter()
{
    bstd_string_result string = bstd_string_new("Hello Wonderful World");

    bstd_result result = bstd_string_replace(&string.value, "Wonderful World", "BSTD");

    ASSERT(result.ok);
    ASSERT_STR_EQ("Hello BSTD", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_beginning()
{
    bstd_string_result string = bstd_string_new("Hello World");

    bstd_result result = bstd_string_replace(&string.value, "Hello", "Hi");

    ASSERT(result.ok);
    ASSERT_STR_EQ("Hi World", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_entire_string()
{
    bstd_string_result string = bstd_string_new("Hello World");

    bstd_result result = bstd_string_replace(&string.value, "Hello World", "BSTD");

    ASSERT(result.ok);
    ASSERT_STR_EQ("BSTD", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_not_found()
{
    bstd_string_result string = bstd_string_new("Hello World");

    bstd_result result = bstd_string_replace(&string.value, "Rust", "C");

    ASSERT(result.ok);
    ASSERT_STR_EQ("Hello World", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_length_grows()
{
    bstd_string_result string = bstd_string_new("abc");

    size_t old_len = string.value.length;

    bstd_result result = bstd_string_replace(&string.value, "a", "abcdef");

    ASSERT(result.ok);
    ASSERT(string.value.length > old_len);

    ASSERT_STR_EQ("abcdefbc", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_length_shrinks()
{
    bstd_string_result string = bstd_string_new("abcdefbc");

    size_t old_len = string.value.length;

    bstd_result result = bstd_string_replace(&string.value, "abcdef", "a");

    ASSERT(result.ok);
    ASSERT(string.value.length < old_len);

    ASSERT_STR_EQ("abc", string.value.data);

    return TEST_OK;
}

test_result test_string_replace_invalid_string()
{
    bstd_result result = bstd_string_replace(NULL, "a", "b");

    ASSERT_NOT(result.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, result.error);

    return TEST_OK;
}

test_result test_string_replace_invalid_search()
{
    bstd_string_result string = bstd_string_new("Hello");

    bstd_result result = bstd_string_replace(&string.value, NULL, "World");

    ASSERT_NOT(result.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, result.error);

    return TEST_OK;
}

test_result test_string_replace_invalid_replace()
{
    bstd_string_result string = bstd_string_new("Hello");

    bstd_result result = bstd_string_replace(&string.value, "Hello", NULL);

    ASSERT_NOT(result.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, result.error);

    return TEST_OK;
}

test_result test_string_replace_empty_search()
{
    bstd_string_result string = bstd_string_new("Hello");

    bstd_result result = bstd_string_replace(&string.value, "", "World");

    ASSERT_NOT(result.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, result.error);

    return TEST_OK;
}

test_result test_string_replace_same_size()
{
    bstd_string_result string = bstd_string_new("Hello World");

    bstd_result result = bstd_string_replace(&string.value, "World", "Rust!");

    ASSERT(result.ok);

    ASSERT_STR_EQ("Hello Rust!", string.value.data);

    return TEST_OK;
}