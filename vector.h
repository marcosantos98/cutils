#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdlib.h>

#define VEC_ADD(vec, item)                                                        \
    do                                                                            \
    {                                                                             \
        if ((vec)->cnt >= (vec)->cap)                                             \
        {                                                                         \
            (vec)->cap = (vec)->cap == 0 ? 32 : (vec)->cap * 2;                   \
            (vec)->data = realloc((vec)->data, sizeof((vec)->data) * (vec)->cap); \
        }                                                                         \
        (vec)->data[(vec)->cnt] = item;                                           \
        (vec)->cnt++;                                                             \
    } while (0)
    
#define VEC_FREE(vec) free(vec.data)

#endif
