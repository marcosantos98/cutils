#include <stdio.h>
#include <stdlib.h>

#include "io.h"

int main(int argc, char **argv) {

    if (argc != 2)
        return 1;

    (void)*argv++;
    const char *path = *argv++;

    size_t len;
    char *content = read_file(path, &len);

    printf("%s content:\n", path);
    printf("%s\n", content);
    printf("%s len: %zu\n", path, len);

    free(content);

    return 0;
}
