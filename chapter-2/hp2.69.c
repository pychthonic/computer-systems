#include <stdio.h>

#include "chapter2.h"


/* 
Do rotating left shift. Assume 0 <= n < w
Examples when x = 0x12345678 and w = 32:
n = 4 --> 0x23456781, n=20 -> 0x67812345
*/

unsigned rotate_left(unsigned x, int n){

    size_t w_count = sizeof(unsigned) << 3;
    
    unsigned shifted_left = x << n;

    unsigned lost_bits = x - (shifted_left >> n);

    return shifted_left + (lost_bits >> (w_count - n));
}


int main() {

    printf("\n");

    // Tests:

    unsigned x = 0x12345678;
    int n = 20;

    printf("rotate_left(0x%08X, %d) --> 0x%08X\n", x, n, rotate_left(x, n));

    n = 4;

    printf("rotate_left(0x%08X, %d) --> 0x%08X\n", x, n, rotate_left(x, n));
    
    printf("\n");

    return 0;
}