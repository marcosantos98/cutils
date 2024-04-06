#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define VEC_ADD(vec, item)                                                         \
    do {                                                                           \
        if ((vec)->cnt >= (vec)->cap) {                                            \
            (vec)->cap = (vec)->cap == 0 ? 32 : (vec)->cap * 2;                    \
            (vec)->data = realloc((vec)->data, sizeof(*(vec)->data) * (vec)->cap); \
        }                                                                          \
        (vec)->data[(vec)->cnt] = item;                                            \
        (vec)->cnt++;                                                              \
    } while (0)

#define VEC_ADD_AT(vec, idx, item)                                                                \
    do {                                                                                          \
        if ((vec)->cnt + 1 >= (vec)->cap || idx >= (vec)->cap) {                                  \
            (vec)->cap = (vec)->cap == 0 ? 32 : (vec)->cap * 2;                                   \
            (vec)->data = realloc((vec)->data, sizeof(*(vec)->data) * (vec)->cap);                \
        }                                                                                         \
        int cnt_at_idx = (vec)->cnt - idx;                                                        \
        memmove((vec)->data + idx + 1, (vec)->data + idx, cnt_at_idx + 1 * sizeof(*(vec)->data)); \
        (vec)->data[idx] = item;                                                                  \
        (vec)->cnt++;                                                                             \
    } while (0)

#define VEC_DEL_AT(vec, idx)                                                                  \
    do {                                                                                      \
        assert((idx >= 0 && idx < (vec)->cnt) && "Invalid index!");                           \
        int cnt_at_idx = (vec)->cnt - idx;                                                    \
        memmove((vec)->data + idx, (vec)->data + idx + 1, cnt_at_idx * sizeof(*(vec)->data)); \
        (vec)->cnt--;                                                                         \
    } while (0)

#define VEC_GET(vec, idx) vec.data[idx]

#define VEC_POP(vec) (vec)->data[--(vec)->cnt]

#define VEC_FREE(vec) free(vec.data)

#endif
