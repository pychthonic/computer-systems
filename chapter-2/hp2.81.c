#include <stdio.h>
#include <sys/types.h>

#include "chapter2.h"


/* 
A.

If w (bit count) is 8, and k is 5, the number we're looking for is:

    1110 0000

If w is 16, and k is 9, the number we're looking for is:

    1111 1110 0000 0000

*/
u_int64_t func_A(size_t k) {
    return ((-1) & ~((1 << k) - 1));
}


/*
B.

If w is 8, k is 2, and j is 3, the number we're looking for is:

    0001 1000

If w is 16, k is 7, and j is 3, the number we're looking for is:

    0000 0011 1111 1000

*/
u_int64_t func_B(size_t j, size_t k) {
    return (((1 << (k + j)) - 1) - ((1 << j) - 1));
}


int main() {
    
    // Tests:

    u_int64_t x;
    size_t k = 3, j = 4;

    x = func_A(k);
    printf("\nfunc_A(%lu) produces bit pattern: \n", k);
    show_bits((byte_pointer) &x, sizeof(x));


    k = 10;
    x = func_A(k);
    printf("\nfunc_A(%lu) produces bit pattern: \n", k);
    show_bits((byte_pointer) &x, sizeof(x));


    k = 3;
    x = func_B(j, k);
    printf("\nfunc_B(%lu, %lu) produces bit pattern: \n", j, k);
    show_bits((byte_pointer) &x, sizeof(x));


    j = 7;
    k = 9;
    x = func_B(j, k);
    printf("\nfunc_B(%lu, %lu) produces bit pattern: \n", j, k);
    show_bits((byte_pointer) &x, sizeof(x));

    printf("\n");

    return 0;
}