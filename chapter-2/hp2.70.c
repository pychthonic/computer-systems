#include <stdio.h>

#include "chapter2.h"


/* 
Return 1 when x can be represented as an n-bit, 2's-complement
number; 0 otherwise
Assume 1 <= n <= w
*/

int fits_bits(int x, int n) {
    size_t w_count = sizeof(unsigned) << 3;

    int n_bit_max_int = (int) ((((unsigned) -1) >> w_count - n ) >> 1);

    int n_bit_min_int = (int) (((unsigned) INT_MIN) >> w_count - n);

    // Extend all the bits of n_bit_min_int to make it negative:
    n_bit_min_int |= n_bit_min_int << 1;
    n_bit_min_int |= n_bit_min_int << 2;
    n_bit_min_int |= n_bit_min_int << 4;
    n_bit_min_int |= n_bit_min_int << 8;
    n_bit_min_int |= n_bit_min_int << 16;

    printf("\nmax int with n %d: %d\n", n, n_bit_max_int);
    printf("min int with n %d: %d\n", n, n_bit_min_int);

    return (x >= n_bit_min_int && x <= n_bit_max_int);

}


int main() {

    printf("\n");

    // Tests:
    int x = -52, n = 20;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));

    x = 0, n = 1;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));

    x = 1, n = 1;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));

    x = 2147483647, n = 32;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));

    x = -2147483648, n = 32;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));

    x = 2147483647, n = 31;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));

    x = -2147483648, n = 31;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));


    x = -8, n = 4;
    printf("fit_bits(%d, %d) --> %d\n", x, n, fits_bits(x, n));
    
    printf("\n");

    return 0;
}