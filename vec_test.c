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

    Ex b = VEC_POP(&vec);

    printf("%s\n", b.data);

    int res = b.i;

    numbers items = {0};

    for (int i = 0; i < 10; i++) {
        VEC_ADD(&items, i);
    }

    VEC_DEL_AT(&items, 5);

    int j = 5;
    for (int i = 20; i < 25; i++) {
        VEC_ADD_AT(&items, j, i);
        j++;
    }

    for (int i = 0; i < items.cnt; i++) {
        printf("[%d] %d\n", i, items.data[i]);
    }

    VEC_FREE(vec);
    VEC_FREE(items);
    return res;
}
