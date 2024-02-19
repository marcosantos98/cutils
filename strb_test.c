#include <stdio.h>

#include "strb.h"

int main(void) {

    strb strb = strb_init(16);
    strb_append(&strb, "Hello World\n");
    strb_append(&strb, "... or mom!\n");

    printf("%s", strb.str);

    strb_free(strb);

    return 0;
}