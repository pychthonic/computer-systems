#include <stdio.h>

#include "chapter2.h"


/* 
Mask with least significant n bits set to 1
Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
Assume 1 <= n <= w
Be careful of the case n = w
*/

int lower_one_mask(int n) {
    int w_count = (int) sizeof(unsigned) << 3;

    unsigned all_ones = (unsigned) -1;

    return (all_ones >> (32 - n));
}


int main() {

    printf("\n");

    // Tests:
    int n = 1;
    printf("lower_one_mask(%d) --> 0x%08X\n", n, lower_one_mask(n));

    n = 6;
    printf("lower_one_mask(%d) --> 0x%08X\n", n, lower_one_mask(n));

    n = 17;
    printf("lower_one_mask(%d) --> 0x%08X\n", n, lower_one_mask(n));

    n = 32;
    printf("lower_one_mask(%d) --> 0x%08X\n", n, lower_one_mask(n));
    
    printf("\n");

    return 0;
}