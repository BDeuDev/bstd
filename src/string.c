#include "bstd/string.h"
#include "bstd/error.h"
#include "bstd/result.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bstd_string_result bstd_string_new(char *cstr)
{
    if (!cstr)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t len = strlen(cstr);
    size_t cap = len > 0 ? len * 2 : 8;

    char *data = malloc(cap + BSTD_STRING_NULL_TERM);
    if (!data)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    memcpy(data, cstr, len + BSTD_STRING_NULL_TERM);

    return (bstd_string_result){.ok = true,
                                .value = {.data = data, .length = len, .capacity = cap}};
}

bstd_string_result bstd_string_slice(const bstd_string *s, size_t start_idx, size_t end_idx)
{
    if (start_idx > end_idx || end_idx > s->length)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OUT_OF_BOUNDS};
    }

    size_t slice_len = end_idx - start_idx;
    size_t slice_cap = slice_len > 0 ? slice_len * 2 : 8;

    char *copy = malloc(slice_cap + BSTD_STRING_NULL_TERM);
    if (!copy)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    memcpy(copy, s->data + start_idx, slice_len);
    copy[slice_len] = '\0';

    bstd_string str = {.data = copy, .length = slice_len, .capacity = slice_cap};

    return (bstd_string_result){.ok = true, .value = str};
}

bstd_result bstd_string_slice_inplace(bstd_string *s, size_t start_idx, size_t end_idx)
{
}

bstd_string_result bstd_string_to_uppercase(const bstd_string *s)
{
    if (!s || !s->data)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t len = s->length;
    char *copy = malloc(s->length + BSTD_STRING_NULL_TERM);

    if (!copy)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    for (size_t x = 0; x < len; x++)
    {
        char r = s->data[x];
        if (r >= 'a' && r <= 'z')
        {
            copy[x] = r - 32;
        }
        else
        {
            copy[x] = r;
        }
    }
    copy[len] = '\0';

    bstd_string str = {.data = copy, .length = len, .capacity = len};

    return (bstd_string_result){.ok = true, .value = str};
}

bstd_result bstd_string_to_uppercase_inplace(bstd_string *s)
{
    if (!s || !s->data)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t len = s->length;

    for (size_t x = 0; x < len; x++)
    {
        char r = s->data[x];
        if (r >= 'a' && r <= 'z')
        {
            s->data[x] = r - 32;
        }
        else
        {
            s->data[x] = r;
        }
    }
    s->data[len] = '\0';

    return (bstd_result){.ok = true, .error = BSTD_OK};
}

bstd_string_result bstd_string_to_lowercase(const bstd_string *s)
{
    if (!s || !s->data)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t len = s->length;
    char *copy = malloc(s->length + BSTD_STRING_NULL_TERM);

    if (!copy)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    for (size_t x = 0; x < len; x++)
    {
        char r = s->data[x];
        if (r >= 'A' && r <= 'Z')
        {
            copy[x] = r + 32;
        }
        else
        {
            copy[x] = r;
        }
    }
    copy[len] = '\0';

    bstd_string str = {.data = copy, .length = len, .capacity = len};

    return (bstd_string_result){.ok = true, .value = str};
}

bstd_result bstd_string_to_lowercase_inplace(bstd_string *s)
{
    if (!s || !s->data)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t len = s->length;

    for (size_t x = 0; x < len; x++)
    {
        char r = s->data[x];
        if (r >= 'A' && r <= 'Z')
        {
            s->data[x] = r + 32;
        }
        else
        {
            s->data[x] = r;
        }
    }
    s->data[len] = '\0';

    return (bstd_result){.ok = false, .error = BSTD_OK};
}

bstd_string_result bstd_string_reverse(bstd_string s)
{

    if (s.data == NULL)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t len = s.length;
    size_t cap = len * 2;
    char *copy = malloc(cap + BSTD_STRING_NULL_TERM);
    if (!copy)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    for (size_t i = 0; i < len; i++)
    {
        memcpy(copy + len - 1 - i, s.data + i, 1);
    }

    copy[len] = '\0';

    bstd_string str = {.data = copy, .capacity = cap, .length = len};

    return (bstd_string_result){.ok = true, .value = str};
}

bstd_string_result bstd_string_concat(bstd_string s, bstd_string d)
{
    if (s.data == NULL || d.data == NULL)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t new_len = s.length + d.length;
    size_t new_cap = new_len * 2;

    char *data = malloc(new_cap + BSTD_STRING_NULL_TERM);
    if (!data)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    memcpy(data, s.data, s.length);
    memcpy(data + s.length, d.data, d.length);

    data[new_len] = '\0';

    bstd_string new_string = {.data = data, .capacity = new_cap, .length = new_len};

    return (bstd_string_result){.ok = true, .value = new_string};
}

bstd_result bstd_string_concat_inplace(bstd_string *s, bstd_string d)
{
    if (s->data == NULL || d.data == NULL)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t new_len = s->length + d.length;

    if (new_len > s->capacity)
    {
        size_t new_cap = new_len * 2;

        char *tmp = realloc(s->data, new_cap + BSTD_STRING_NULL_TERM);
        if (!tmp)
        {
            return (bstd_result){.ok = false, .error = BSTD_ERR_OOM};
        }

        s->data = tmp;
        s->capacity = new_cap;
    }

    memcpy(s->data + s->length, d.data, d.length);

    s->length = new_len;
    s->data[new_len] = '\0';

    return (bstd_result){.ok = true, .error = BSTD_OK};
}

bstd_result bstd_string_replace(bstd_string *s, const char *search, const char *replace)
{
    if (!s || !s->data || !search || !replace)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t search_len = strlen(search);
    size_t replace_len = strlen(replace);

    if (search_len == 0)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    char *match = strstr(s->data, search);

    if (!match)
    {
        return (bstd_result){.ok = true, .error = BSTD_OK};
    }

    size_t prefix_len = (size_t)(match - s->data);

    size_t new_len = s->length - search_len + replace_len;

    if (new_len > s->capacity)
    {
        size_t new_cap = new_len * 2;

        char *tmp = realloc(s->data, new_cap + BSTD_STRING_NULL_TERM);

        if (!tmp)
        {
            return (bstd_result){.ok = false, .error = BSTD_ERR_OOM};
        }

        s->data = tmp;
        s->capacity = new_cap;

        match = s->data + prefix_len;
    }

    memmove(match + replace_len, match + search_len, s->length - prefix_len - search_len + 1);

    memcpy(match, replace, replace_len);

    s->length = new_len;

    return (bstd_result){.ok = true, .error = BSTD_OK};
}

bstd_result bstd_string_push_char(bstd_string *s, char c)
{
    if (s->data == NULL)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_INVALID_ARG};
    }

    size_t new_len = s->length + 1;

    if (new_len > s->capacity)
    {
        size_t new_cap = (s->capacity == 0) ? 8 : s->capacity * 2;
        char *tmp = realloc(s->data, new_cap + BSTD_STRING_NULL_TERM);

        if (!tmp)
        {
            return (bstd_result){.ok = false, .error = BSTD_ERR_OOM};
        }

        s->data = tmp;
        s->capacity = new_cap;
    }

    s->data[s->length] = c;
    s->length = new_len;
    s->data[s->length] = '\0';

    return (bstd_result){.ok = true, .error = BSTD_OK};
}

void bstd_string_clear(bstd_string *s)
{
    s->length = 0;

    if (s->data)
    {
        s->data[0] = '\0';
    }
}

void bstd_string_destroy(bstd_string *s)
{
    free(s->data);

    s->data = NULL;
    s->length = 0;
    s->capacity = 0;
}

bstd_result bstd_string_reserve(bstd_string *s, size_t n)
{
    if (n <= s->capacity)
    {
        return (bstd_result){.ok = true, .error = BSTD_OK};
    }

    char *tmp = realloc(s->data, n + 1);

    if (!tmp)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    s->data = tmp;
    s->capacity = n;

    return (bstd_result){.ok = true, .error = BSTD_OK};
}

bstd_result bstd_string_shrink_to_fit(bstd_string *s)
{
    if (s->capacity == s->length)
    {
        return (bstd_result){.ok = true, .error = BSTD_OK};
    }

    char *tmp = realloc(s->data, s->length + BSTD_STRING_NULL_TERM);
    if (!tmp)
    {
        return (bstd_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    s->data = tmp;
    s->capacity = s->length;

    return (bstd_result){.ok = true, .error = BSTD_OK};
}

bstd_string_result bstd_string_clone(bstd_string *s)
{
    size_t len = s->length;
    size_t cap = s->capacity;

    char *clone = malloc(s->length + BSTD_STRING_NULL_TERM);

    if (!clone)
    {
        return (bstd_string_result){.ok = false, .error = BSTD_ERR_OOM};
    }

    memcpy(clone, s->data, s->length + BSTD_STRING_NULL_TERM);

    bstd_string clone_str = {.data = clone, .length = len, .capacity = cap};

    return (bstd_string_result){.ok = true, .value = clone_str};
}