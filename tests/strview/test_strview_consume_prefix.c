#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_consume_prefix()
{
    const char *cstr = "Hello World";
    const char *pstr = "He";
    const char *consumed = "llo World";
    size_t len = strlen(consumed);

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview prefix = bstd_strview_new(pstr);

    bool result = bstd_strview_consume_prefix(&strview, prefix);

    ASSERT(result);
    ASSERT_STR_EQ(consumed, strview.data);
    ASSERT_EQ(len, strview.length);

    return TEST_OK;
}

test_result test_strview_consume_prefix_wrong()
{
    const char *cstr = "Hello World";
    const char *pstr = "DD";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview prefix = bstd_strview_new(pstr);

    bool result = bstd_strview_consume_prefix(&strview, prefix);

    ASSERT_NOT(result);

    return TEST_OK;
}

test_result test_strview_consume_prefix_empty()
{
    const char *cstr = "Hello World";
    const char *pstr = "";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview prefix = bstd_strview_new(pstr);

    bool result = bstd_strview_consume_prefix(&strview, prefix);

    ASSERT_NOT(result);

    return TEST_OK;
}

test_result test_strview_consume_prefix_empty_source()
{
    const char *cstr = "";
    const char *pstr = "He";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview prefix = bstd_strview_new(pstr);

    bool result = bstd_strview_consume_prefix(&strview, prefix);

    ASSERT_NOT(result);

    return TEST_OK;
}

test_result test_strview_consume_prefix_null()
{
    const char *cstr = "Hello World";
    const char *pstr = "He";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview prefix = bstd_strview_new(pstr);

    strview.data = NULL;

    bool result = bstd_strview_consume_prefix(&strview, prefix);

    ASSERT_NOT(result);

    return TEST_OK;
}