#include "bstd/strview.h"

#include <stdio.h>

int main(void)
{
    printf("=== bstd_strview ===\n\n");

    bstd_strview hello = bstd_strview_new("Hello World");

    printf("print:\n");
    bstd_strview_print(hello);

    printf("print raw: ");
    bstd_strview_print_raw(hello);
    printf("\n");

    bstd_strview_result slice = bstd_strview_slice(hello, 0, 5);

    printf("slice: ");
    bstd_strview_print(slice.value);

    printf("starts_with: %d\n", bstd_strview_starts_with(hello, bstd_strview_new("Hello")));

    printf("ends_with: %d\n", bstd_strview_ends_with(hello, bstd_strview_new("World")));

    printf("includes: %d\n", bstd_strview_includes(hello, bstd_strview_new("lo Wo")));

    printf("equals: %d\n", bstd_strview_equals(hello, bstd_strview_new("Hello World")));

    printf("starts_with false: %d\n", bstd_strview_starts_with(hello, bstd_strview_new("World")));

    printf("ends_with false: %d\n", bstd_strview_ends_with(hello, bstd_strview_new("Hello")));

    printf("includes false: %d\n", bstd_strview_includes(hello, bstd_strview_new("Rust")));

    printf("equals false: %d\n", bstd_strview_equals(hello, bstd_strview_new("Hello")));

    printf("\nnext_char:\n");

    bstd_strview cursor = hello;
    char c;

    while (bstd_strview_next_char(&cursor, &c))
    {
        printf("[%c] ", c);
    }

    printf("\n\n");

    cursor = hello;

    bstd_strview_advance(&cursor, 6);

    printf("advance: ");
    bstd_strview_print(cursor);

    cursor = hello;

    bstd_strview_consume_prefix(&cursor, bstd_strview_new("Hello "));

    printf("consume_prefix: ");
    bstd_strview_print(cursor);

    printf("empty: %d\n", bstd_strview_is_empty(BSTD_STRVIEW_EMPTY));

    bstd_strview trim = bstd_strview_new("   Hello World   ");

    bstd_strview_trim_left(&trim);

    printf("trim_left: ");
    bstd_strview_print(trim);

    trim = bstd_strview_new("   Hello World   ");

    bstd_strview_trim_right(&trim);

    printf("trim_right: ");
    bstd_strview_print(trim);

    trim = bstd_strview_new("   Hello World   ");

    bstd_strview_trim(&trim);

    printf("trim: ");
    bstd_strview_print(trim);

    printf("\nsplit:\n");

    bstd_strview csv = bstd_strview_new("red,green,blue");

    bstd_strview_split_iter iter = bstd_strview_split(&csv, bstd_strview_new(","));

    bstd_strview token;

    while ((token = bstd_strview_split_iter_next(&iter)).data)
    {
        bstd_strview_print(token);
    }

    printf("\nsplit_once:\n");

    bstd_strview pair = bstd_strview_new("name=Bernabe");

    bstd_strview_split_once_result split = bstd_strview_split_once(&pair, bstd_strview_new("="));

    printf("left: ");
    bstd_strview_print(split.left);

    printf("right: ");
    bstd_strview_print(split.right);

    printf("\nsplit_once not found:\n");

    bstd_strview no_sep = bstd_strview_new("Bernabe");

    bstd_strview_split_once_result no_split =
        bstd_strview_split_once(&no_sep, bstd_strview_new("="));

    printf("left: ");
    bstd_strview_print(no_split.left);

    printf("right: ");
    bstd_strview_print(no_split.right);

    printf("\nsplit_lines:\n");

    bstd_strview lines = bstd_strview_new("one\ntwo\nthree");

    iter = bstd_strview_split_lines(&lines);

    while ((token = bstd_strview_split_iter_next(&iter)).data)
    {
        bstd_strview_print(token);
    }

    return 0;
}