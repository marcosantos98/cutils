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

int main(void)
{

    Ex a = {
        .i = 69,
        .data = "Hello World",
    };

    ExVec vec = {0};
    VEC_ADD(&vec, a);

    Ex b = vec.data[0];

    printf("%s\n", b.data);

    int res = b.i;

    VEC_FREE(vec);

    return res;
}