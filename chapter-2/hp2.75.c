#include <stdio.h>
#include <sys/types.h>

#include "chapter2.h"


/* Writing my own signed_high_prod() so I can test
unsigned_high_prod:*/
int signed_high_prod(int x, int y) {
    int64_t full_product = (int64_t) x * (int64_t) y;
    printf("\n");

    printf("\nBytes/bits for %ld:\n", full_product);
    //show_bytes((byte_pointer) &full_product, sizeof(full_product));
    show_bits((byte_pointer) &full_product, sizeof(full_product));
    int high_prod = (full_product >> 32);

    printf("\nBytes/bits for %d:\n", high_prod);
    show_bits((byte_pointer) &high_prod, sizeof(high_prod));

    return high_prod;
}

/* I made this to test signed_high_prod() */
int signed_low_prod(int x, int y) {
    return x * y;
}

/* This will work, due to the bit-level equivalence of 
signed and unsigned multiplication. */
int unsigned_high_prod(unsigned x, unsigned y) {
    return (unsigned) signed_high_prod((int) x, (int) y);
}



int main() {
    
    // Tests:

    int x, y;

    x = -5000;
    y = INT_MAX - 5;

    int z = x * y;

    printf("\nBytes/bits for %d:\n", x);
    //show_bytes((byte_pointer) &x, sizeof(x));
    show_bits((byte_pointer) &x, sizeof(x));

    printf("\nBytes/bits for %d:\n", y);
    //show_bytes((byte_pointer) &y, sizeof(y));
    show_bits((byte_pointer) &y, sizeof(y));

    printf("\nBytes/bits for (int) %d x %d:\n", x, y);
    //show_bytes((byte_pointer) &z, sizeof(z));
    show_bits((byte_pointer) &z, sizeof(z));

    z = signed_low_prod(x, y);
    printf("\nBytes/bits for signed_low_prod(%d, %d):\n", x, y);
    //show_bytes((byte_pointer) &z, sizeof(z));
    show_bits((byte_pointer) &z, sizeof(z));


    printf("\nsigned_high_prod(%d, %d) --> %d\n", x, y, signed_high_prod(x, y));
    printf("\nunsigned_high_prod(%d, %d) --> %u\n", x, y, unsigned_high_prod(x, y));


    printf("\n");

    return 0;
}