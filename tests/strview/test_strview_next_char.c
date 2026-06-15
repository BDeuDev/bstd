#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_next_char()
{
    const char *cstr = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    char out;

    while (strview.length)
    {
        char c = strview.data[0];
        if (bstd_strview_next_char(&strview, &out))
        {
            ASSERT_EQ(c, out);
        }
    }

    return TEST_OK;
}

test_result test_strview_next_char_null()
{
    const char *cstr = "Hello World";

    bstd_strview strview = bstd_strview_new(cstr);

    strview.data = NULL;

    char out;

    ASSERT_NOT(bstd_strview_next_char(&strview, &out));

    return TEST_OK;
}

test_result test_strview_next_char_empty()
{
    const char *cstr = "";

    bstd_strview strview = bstd_strview_new(cstr);

    char out;

    ASSERT_NOT(bstd_strview_next_char(&strview, &out));

    return TEST_OK;
}