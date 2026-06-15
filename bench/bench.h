#ifndef BSTD_BENCH_H
#define BSTD_BENCH_H

#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>

typedef struct {
    const char *name;
    long iterations;
} bench_case;

static inline long bench_now_ns()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000000L + ts.tv_nsec;
}

#define BENCH(name, iters, code)                               \
    do {                                                       \
        long _iters = (long)(iters);                           \
        long start = bench_now_ns();                           \
        for (long i = 0; i < _iters; i++) {                  \
            code;                                              \
        }                                                      \
        long end = bench_now_ns();                             \
        printf("[%s] %ld ms (%ld iters)\n",                   \
               name,                                           \
               (end - start) / 1000000,                       \
               _iters);                                        \
    } while (0)
#endif