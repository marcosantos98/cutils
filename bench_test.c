#include "bench.h"

int main(void) {

    bench b = {0};

    BENCH_START(&b);
    unsigned int i = 0;
    for (; i < 10000000; i++)
        printf("%u\n", i);
    BENCH_MEASURE(&b, "One million loop");
}