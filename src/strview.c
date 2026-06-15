#include "bstd/strview.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bstd_strview bstd_strview_new(const char *cstr)
{
    return (bstd_strview){.data = cstr, .length = strlen(cstr)};
}

void bstd_strview_print(bstd_strview s)
{
    printf("%.*s\n", (int)s.length, s.data);
}

void bstd_strview_print_raw(bstd_strview s)
{
    printf("%.*s", (int)s.length, s.data);
}

bstd_strview_result bstd_strview_slice(bstd_strview s, size_t start_idx, size_t end_idx)
{
    if (start_idx > end_idx || end_idx > s.length)
    {
        return (bstd_strview_result){.ok = false, .error = BSTD_ERR_OUT_OF_BOUNDS};
    }

    bstd_strview str = {.data = s.data + start_idx, .length = end_idx - start_idx};

    return (bstd_strview_result){.ok = true, .value = str};
}

bool bstd_strview_starts_with(bstd_strview s, bstd_strview prefix)
{
    if (s.data == NULL || prefix.data == NULL)
        return false;

    if (prefix.length > s.length || prefix.length == 0)
        return false;

    return memcmp(s.data, prefix.data, prefix.length) == 0;
}

bool bstd_strview_ends_with(bstd_strview s, bstd_strview sufix)
{
    if (sufix.length > s.length || sufix.length == 0)
        return false;

    return memcmp(s.data + s.length - sufix.length, sufix.data, sufix.length) == 0;
}

bool bstd_strview_includes(bstd_strview s, bstd_strview search)
{
    if (search.length > s.length || search.length == 0)
        return false;

    for (size_t i = 0; i <= s.length - search.length; i++)
    {
        if (memcmp(s.data + i, search.data, search.length) == 0)
            return true;
    }

    return false;
}

bool bstd_strview_equals(bstd_strview s, bstd_strview c)
{
    if (s.length != c.length)
        return false;

    if (memcmp(s.data, c.data, c.length) == 0)
        return true;

    return false;
}

bool bstd_strview_next_char(bstd_strview *s, char *out)
{
    if (s->length == 0 || s->data == NULL || out == NULL || s == NULL)
    {
        return false;
    }

    *out = s->data[0];
    s->data += 1;
    s->length -= 1;

    return true;
}

bool bstd_strview_advance(bstd_strview *s, size_t n)
{
    if (n > s->length || n <= 0 || s->data == NULL)
        return false;

    s->data += n;
    s->length -= n;

    return true;
}

bool bstd_strview_consume_prefix(bstd_strview *s, bstd_strview prefix)
{
    bool r = bstd_strview_starts_with(*s, prefix);

    if (!r)
        return false;

    return bstd_strview_advance(s, prefix.length);
}

bool bstd_strview_is_empty(bstd_strview s)
{
    if (s.length == 0)
        return true;

    for (size_t i = 0; i < s.length; i++)
    {
        if (!isspace((unsigned char)s.data[i]))
        {
            return false;
        }
    }

    return true;
}

void bstd_strview_trim_left(bstd_strview *s)
{
    bstd_strview c = *s;
    for (size_t i = 0; i < c.length; i++)
    {
        if (!isspace((unsigned char)c.data[i]))
        {
            return;
        }
        s->data += 1;
        s->length -= 1;
    }
}

void bstd_strview_trim_right(bstd_strview *s)
{
    bstd_strview c = *s;
    for (size_t i = 0; i < c.length; i++)
    {
        if (!isspace((unsigned char)c.data[c.length - 1 - i]))
        {
            return;
        }
        s->length -= 1;
    }
}

void bstd_strview_trim(bstd_strview *s)
{
    bstd_strview_trim_left(s);
    bstd_strview_trim_right(s);
}

bstd_strview_split_iter bstd_strview_split(bstd_strview *s, bstd_strview q)
{
    return (bstd_strview_split_iter){.source = *s, .qry = q, .current_index = 0};
}

bstd_strview_split_once_result bstd_strview_split_once(bstd_strview *s, bstd_strview q)
{
    if (s == NULL || s->data == NULL || q.length == 0)
    {
        return (bstd_strview_split_once_result){.left = BSTD_STRVIEW_EMPTY,
                                                .right = BSTD_STRVIEW_EMPTY};
    }

    for (size_t i = 0; i < s->length; i++)
    {
        if (match_at(*s, i, q))
        {
            bstd_strview left = {.data = s->data, .length = i};

            bstd_strview right = {.data = s->data + i + q.length,
                                  .length = s->length - i - q.length};

            return (bstd_strview_split_once_result){.left = left, .right = right};
        }
    }

    return (bstd_strview_split_once_result){.left = *s, .right = BSTD_STRVIEW_EMPTY};
}

bstd_strview_split_iter bstd_strview_split_lines(bstd_strview *s)
{
    bstd_strview qry = bstd_strview_new("\n");

    return (bstd_strview_split_iter){
        .source = *s,
        .qry = qry,
        .current_index = 0,
    };
}

bstd_strview bstd_strview_split_iter_next(bstd_strview_split_iter *iter)
{
    if (iter->current_index >= iter->source.length)
    {
        return BSTD_STRVIEW_EMPTY;
    }

    size_t start = iter->current_index;

    for (size_t i = iter->current_index; i < iter->source.length; i++)
    {
        if (match_at(iter->source, i, iter->qry))
        {
            bstd_strview result = {.data = iter->source.data + start, .length = i - start};

            iter->current_index = i + iter->qry.length;
            return result;
        }
    }

    bstd_strview result = {.data = iter->source.data + start,
                           .length = iter->source.length - start};

    iter->current_index = iter->source.length;
    return result;
}

int match_at(bstd_strview src, size_t pos, bstd_strview qry)
{
    if (pos + qry.length > src.length)
        return 0;

    return memcmp(src.data + pos, qry.data, qry.length) == 0;
}