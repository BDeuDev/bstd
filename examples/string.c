#include "bstd/string.h"

#include <stdio.h>

int main(void)
{
    printf("=== bstd_string ===\n\n");

    bstd_string_result hello = bstd_string_new("Hello World");

    printf("new: %s\n", hello.value.data);

    bstd_string_result slice = bstd_string_slice(&hello.value, 0, 5);

    printf("slice: %s\n", slice.value.data);

    bstd_string_result invalid_slice = bstd_string_slice(&hello.value, 50, 100);

    printf("invalid slice ok: %d\n", invalid_slice.ok);

    printf("\nerror handling:\n");

    bstd_string_result null_str = bstd_string_new(NULL);

    printf("new(NULL) -> ok=%d error=%d\n", null_str.ok, null_str.error);

    bstd_string_result upper = bstd_string_to_uppercase(&hello.value);

    printf("uppercase: %s\n", upper.value.data);

    bstd_string_result lower = bstd_string_to_lowercase(&upper.value);

    printf("lowercase: %s\n", lower.value.data);

    bstd_string_to_uppercase_inplace(&hello.value);

    printf("uppercase inplace: %s\n", hello.value.data);

    bstd_string_to_lowercase_inplace(&hello.value);

    printf("lowercase inplace: %s\n", hello.value.data);

    bstd_string_result reversed = bstd_string_reverse(hello.value);

    printf("reverse: %s\n", reversed.value.data);

    bstd_string_result rust = bstd_string_new(" Rust");

    bstd_string_result concat = bstd_string_concat(hello.value, rust.value);

    printf("concat: %s\n", concat.value.data);

    bstd_string_concat_inplace(&hello.value, rust.value);

    printf("concat inplace: %s\n", hello.value.data);

    bstd_string_replace(&hello.value, "Rust", "BSTD");

    printf("replace: %s\n", hello.value.data);

    bstd_string_push_char(&hello.value, '!');

    printf("push char: %s\n", hello.value.data);

    printf("capacity before reserve: %zu\n", hello.value.capacity);

    bstd_string_reserve(&hello.value, 128);

    printf("capacity after reserve: %zu\n", hello.value.capacity);

    size_t old_cap = hello.value.capacity;

    bstd_string_reserve(&hello.value, 4);

    printf("reserve smaller -> cap=%zu (was %zu)\n", hello.value.capacity, old_cap);

    bstd_string_shrink_to_fit(&hello.value);

    printf("capacity after shrink: %zu\n", hello.value.capacity);

    bstd_string_result clone = bstd_string_clone(&hello.value);

    printf("clone: %s\n", clone.value.data);

    bstd_string_clear(&clone.value);

    printf("clear len: %zu\n", clone.value.length);

    printf("clear data: \"%s\"\n", clone.value.data);

    bstd_string_destroy(&clone.value);

    printf("destroy -> data=%p len=%zu cap=%zu\n", (void *)clone.value.data, clone.value.length,
           clone.value.capacity);

    bstd_string_destroy(&slice.value);
    bstd_string_destroy(&upper.value);
    bstd_string_destroy(&lower.value);
    bstd_string_destroy(&reversed.value);
    bstd_string_destroy(&rust.value);
    bstd_string_destroy(&concat.value);
    bstd_string_destroy(&hello.value);

    return 0;
}