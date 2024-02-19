#ifndef _STRB_H
#define _STRB_H

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    size_t cnt;
    size_t cap;
} strb;

strb strb_init(int initial_cap) {
    return (strb){
        .str = (char *)malloc(initial_cap),
        .cnt = 0,
        .cap = initial_cap,
    };
}

void strb_append(strb *strb, const char *to_append) {
    size_t to_append_len = strlen(to_append);
    if (strb->cnt + to_append_len > strb->cap) {
        strb->cap *= 2;
        strb->str = (char *)realloc(strb->str, sizeof(strb->str) * strb->cap);
    }

    memcpy(strb->str + strb->cnt, to_append, to_append_len);
    strb->cnt += to_append_len;
}

void strb_free(strb strb) {
    free(strb.str);
}

#endif