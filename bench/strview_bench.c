#include "bench.h"
#include "bstd/strview.h"

#include <string.h>
#include <stdio.h>
#include <stdint.h>

static volatile unsigned long long sink;

static inline void blackhole(const void *p)
{
    sink ^= (unsigned long long)(uintptr_t)p;
}

void bench_strview()
{
    printf("=== STRVIEW BENCH ===\n");

    bstd_strview s =
        bstd_strview_new("hello world hello world hello");

    BENCH("bstd_includes", 200000, {
        bstd_strview_includes(s, bstd_strview_new("world"));
    });

    BENCH("libc_strstr", 200000, {
        blackhole(strstr("hello world hello world hello", "world"));
    });

    BENCH("bstd_trim", 200000, {
        bstd_strview t = bstd_strview_new("   hello world   ");
        bstd_strview_trim(&t);

        blackhole(t.data);
    });

    BENCH("manual_trim", 200000, {
        const char *x = "   hello world   ";
        while (*x == ' ') x++;

        blackhole(x);
    });

    BENCH("bstd_split_once", 100000, {
        bstd_strview p = bstd_strview_new("name=value");

        bstd_strview_split_once_result r =
            bstd_strview_split_once(&p, bstd_strview_new("="));

        blackhole(r.left.data);
        blackhole(r.right.data);
    });

    BENCH("manual_find_char", 100000, {
        const char *p = "name=value";
        while (*p && *p != '=') p++;

        blackhole(p);
    });

    printf("\n");
}