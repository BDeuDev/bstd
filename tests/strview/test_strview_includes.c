#include "../test.h"
#include "bstd/strview.h"

test_result test_strview_includes()
{
    const char *cstr = "Hello World";
    const char *query = "He";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview sv_query = bstd_strview_new(query);

    bool includes = bstd_strview_includes(strview, sv_query);

    ASSERT(includes);

    return TEST_OK;
}

test_result test_strview_includes_failed()
{
    const char *cstr = "Hello World";
    const char *query = "das";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview sv_query = bstd_strview_new(query);

    bool includes = bstd_strview_includes(strview, sv_query);

    ASSERT_NOT(includes);

    return TEST_OK;
}

test_result test_strview_includes_empty()
{
    const char *cstr = "Hello World";
    const char *query = "";

    bstd_strview strview = bstd_strview_new(cstr);
    bstd_strview sv_query = bstd_strview_new(query);

    bool includes = bstd_strview_includes(strview, sv_query);

    ASSERT_NOT(includes);

    return TEST_OK;
}