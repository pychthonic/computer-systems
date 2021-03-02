#include <stdio.h>

#include "chapter2.h"


/* 

The bad code given to fix is this:

int xbyte_bad(packed_t word, int bytenum) {
    return (word >> (bytenum << 3)) & 0xFF;
}

This function won't work properly because it will
clear all the bits except the least significant byte,
which means negative numbers won't be sign-extended.

*/

typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer.
Must only use left and right shifts, and one
subtraction.
*/
int xbyte(packed_t word, int bytenum) {

    word = (word >> (bytenum << 3));

    word = word << 24;

    return ((int) word) >> 24;
}


int main() {

    printf("\n");

    // Tests:

    packed_t x = 0x52253223;
    int n = 2;

    printf("\nxbyte(0x%08X, %d) --> 0x%08X a/k/a decimal %d\n", x, n, xbyte(x, n), xbyte(x, n));

    x = (packed_t) -1;
    n = 3;

    printf("\nxbyte(0x%08X, %d) --> 0x%08X a/k/a decimal %d\n", x, n, xbyte(x, n), xbyte(x, n));

    x = 0xF5235110;
    n = 1;

    printf("\nxbyte(0x%08X, %d) --> 0x%08X a/k/a decimal %d\n", x, n, xbyte(x, n), xbyte(x, n));

    x = 0x71538598;
    n = 3;

    printf("\nxbyte(0x%08X, %d) --> 0x%08X a/k/a decimal %d\n", x, n, xbyte(x, n), xbyte(x, n));

    x = 0x81538598;
    n = 3;

    printf("\nxbyte(0x%08X, %d) --> 0x%08X a/k/a decimal %d\n", x, n, xbyte(x, n), xbyte(x, n));

    
    printf("\n");

    return 0;
}