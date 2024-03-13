#include <stdio.h>

#include "vector.h"

typedef struct
{
    int i;
    const char *data;
} Ex;

typedef struct
{
    Ex *data;
    int cap;
    int cnt;
} ExVec;

typedef struct {
    int *data;
    int cnt;
    int cap;
} numbers;

int main(void) {

    Ex a = {
        .i = 69,
        .data = "Hello World",
    };

    ExVec vec = {0};
    VEC_ADD(&vec, a);

    Ex b = vec.data[0];

    printf("%s\n", b.data);

    int res = b.i;

    numbers items = {0};

    for (int i = 0; i < 100; i++) {
        VEC_ADD(&items, i);
    }

    for (int i = 0; i < items.cnt; i++) {
        printf("%d\n", items.data[i]);
    }

    VEC_FREE(vec);
    VEC_FREE(items);
    return res;
}
