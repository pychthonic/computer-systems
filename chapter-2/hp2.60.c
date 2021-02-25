#include <stdio.h>

#include "chapter2.h"

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    
    // safety first:
    if ((i < 0) || (i >= sizeof(unsigned))) {
        return x;
    }

    unsigned char* pointy = (unsigned char *) &x;
    pointy += i;
    *pointy = b;

    return x;
}


int main() {

    unsigned x = 65;
    
    printf("original x: 0x%X\n", x);
    show_bytes((byte_pointer) &x, sizeof(x));

    x = replace_byte(x, 2, 0x18);

    printf("new x, after changing bits #16-23 to 0x18: 0x%X\n", x);
    show_bytes((byte_pointer) &x, sizeof(x));

    x = replace_byte(0x12345678, 2, 0xAB);
    printf("replace_byte(0x12345678, 2, 0xAB) --> 0x%X\n", x);

    x = replace_byte(0x12345678, 0, 0xAB);
    printf("replace_byte(0x12345678, 0, 0xAB) --> 0x %X\n", x);

    return 0;
}