#include "../test.h"
#include "bstd/string.h"

test_result test_string_concat_inplace()
{
    char *cstr1 = "Hello";
    char *cstr2 = " World";
    char *concat_result = "Hello World";

    bstd_string_result string1 = bstd_string_new(cstr1);
    bstd_string_result string2 = bstd_string_new(cstr2);

    bstd_result str_concat = bstd_string_concat_inplace(&string1.value, string2.value);

    ASSERT(str_concat.ok);
    ASSERT_STR_EQ(concat_result, string1.value.data);

    return TEST_OK;
}

test_result test_string_concat_inplace_null()
{
    char *cstr1 = "Hello";
    char *cstr2 = " World";

    bstd_string_result string1 = bstd_string_new(cstr1);
    bstd_string_result string2 = bstd_string_new(cstr2);

    bstd_string_destroy(&string1.value);
    bstd_string_destroy(&string2.value);

    bstd_result str_concat = bstd_string_concat_inplace(&string1.value, string2.value);

    ASSERT_NOT(str_concat.ok);
    ASSERT_EQ(BSTD_ERR_INVALID_ARG, str_concat.error);

    return TEST_OK;
}
