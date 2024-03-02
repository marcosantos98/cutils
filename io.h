#ifndef _IO_H_
#define _IO_H_

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define DEFER_FSEEK(fd, off, whence)                                            \
    do {                                                                        \
        if (fseek(fd, off, whence) != 0) {                                      \
            fprintf(stderr, "ERR: fseek failed. errno: %s\n", strerror(errno)); \
            goto defer;                                                         \
        }                                                                       \
    } while (0)

#define DEFER_FTELL(fd, len_ptr)                                                \
    do {                                                                        \
        int len = ftell(fd);                                                    \
        if (len == -1) {                                                        \
            fprintf(stderr, "ERR: ftell failed. errno: %s\n", strerror(errno)); \
            goto defer;                                                         \
        } else {                                                                \
            *len_ptr = len;                                                     \
        }                                                                       \
    } while (0)

char *read_file(const char *path, size_t *out_size) {

    FILE *fd = fopen(path, "r");
    if (fd == NULL) {
        fprintf(stderr, "ERR: fopen failed. errno: %s\n", strerror(errno));
        return NULL;
    }

    DEFER_FSEEK(fd, 0, SEEK_END);
    DEFER_FTELL(fd, out_size);
    DEFER_FSEEK(fd, 0, SEEK_SET);

    char *res = malloc(sizeof(char) * (*out_size + 1));
    fread(res, sizeof(char), *out_size, fd);
    res[*out_size + 1] = 0;

    return res;

defer:
    fclose(fd);
    return NULL;
}

#endif
