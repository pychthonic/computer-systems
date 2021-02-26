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
        printf(" %.2X", start[i]);
    }
    printf("\n");
}

void show_bits(byte_pointer start, size_t len) {
    printf("Bits:  ");
    unsigned int bit;
    unsigned char temp_byte;
    for (int i=0; i<len; i++) { 
        for (int j=8; j>0; j--) {
            if (j == 4) {
                printf(" ");
            }
            temp_byte = start[i] >> j - 1;
            bit = temp_byte & 1; 
            printf("%d", bit);
        }
        if ( i < len - 1 )
            printf(" | ");
    }
    printf("\n");
}