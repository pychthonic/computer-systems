#include <stdio.h>

#include "chapter2.h"

// The machine I ran this on, like most computers these days, is
// little endian.


void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}



int main() {
    int x = 4;
    printf("x = 4. Here are the bytes for x:");
    show_bytes((byte_pointer) &x, sizeof(x));
    return 0;
}