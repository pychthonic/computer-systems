#include <stdio.h>

#include "chapter2.h"

int is_little_endian() {
    // returns 1 when compiled and run on a little-endian machine,
    // returns 0 when compiled and run on a big-endian machine.

    int test_int = 5;
    unsigned char* pointy = (unsigned char*) &test_int;
    
    return *pointy == 5;
}


int main() {
    
    if (is_little_endian()) {
        printf("This machine is little endian.\n");
    } else {
        printf("This machine is big endian.\n");
    }

    return 0;
}