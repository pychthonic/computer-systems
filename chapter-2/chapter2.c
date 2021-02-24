/*
This file will store functions I write in the homework problems
which are used in other problems so I can easily include them
in future compilations like so:

gcc -o new_binary hpx.x.c chapter2.c

This way, I don't have to include files associated with a previous
problem which will create a compiler error by defining multiple
main functions.
*/

#ifndef CHAPTER2_H
#include "chapter2.h"
#endif

#ifndef STDIO_H
#include <stdio.h>
#endif


void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}