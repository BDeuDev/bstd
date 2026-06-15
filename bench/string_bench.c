#include "bench.h"
#include "bstd/string.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// evita optimización agresiva
static volatile unsigned long long sink;

static inline void blackhole(const void *p)
{
    sink ^= (unsigned long long)(uintptr_t)p;
}

void bench_string()
{
    printf("=== STRING BENCH ===\n");

    BENCH("bstd_push_char", 100000, {
        bstd_string_result s = bstd_string_new("a");
        bstd_string_push_char(&s.value, 'x');

        blackhole(s.value.data);
        bstd_string_destroy(&s.value);
    });

    BENCH("raw_realloc_append", 100000, {
        char *s = malloc(2);
        s[0] = 'a';
        s[1] = '\0';

        size_t len = strlen(s);

        char *new_s = realloc(s, len + 2);
        new_s[len] = 'x';
        new_s[len + 1] = '\0';

        blackhole(new_s);

        free(new_s);
    });

    BENCH("bstd_concat", 50000, {
        bstd_string_result a = bstd_string_new("hello");
        bstd_string_result b = bstd_string_new("world");
        bstd_string_result c = bstd_string_concat(a.value, b.value);

        blackhole(c.value.data);

        bstd_string_destroy(&a.value);
        bstd_string_destroy(&b.value);
        bstd_string_destroy(&c.value);
    });

    BENCH("strcat_baseline", 50000, {
        char buf[64] = "hello";
        strcat(buf, "world");

        blackhole(buf);
    });

    BENCH("bstd_replace", 50000, {
        bstd_string_result s = bstd_string_new("hello world");
        bstd_string_replace(&s.value, "world", "bstd");

        blackhole(s.value.data);
        bstd_string_destroy(&s.value);
    });

    printf("\n");
}