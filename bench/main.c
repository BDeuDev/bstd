#include "bench.h"

void bench_string();
void bench_strview();

int main()
{
    printf("=== BSTD BENCHMARKS ===\n\n");

    bench_string();
    bench_strview();

    return 0;
}