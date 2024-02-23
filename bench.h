#ifndef _BENCH_H_
#define _BENCH_H_

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "vector.h"

typedef struct {
    clock_t start;
    clock_t diff;
} bench;

#define BENCH_START(bench_ptr)        \
    do {                              \
        (bench_ptr)->start = clock(); \
    } while (0);

#define BENCH_MEASURE(bench_ptr, measure_name)                                          \
    do {                                                                                \
        (bench_ptr)->diff = clock() - (bench_ptr)->start;                               \
        printf("=> Measured \033[32m`%s`\033[39m:\n", measure_name);                    \
        printf("    Sec: %.2fs\n", (bench_ptr)->diff / (double)CLOCKS_PER_SEC);         \
        printf("    Ms: %.2fms\n", ((bench_ptr)->diff / (double)CLOCKS_PER_SEC) * 1000); \
        BENCH_START(bench_ptr);                                                         \
    } while (0)

#endif
