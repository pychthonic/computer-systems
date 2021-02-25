#include <stdio.h>

#include "chapter2.h"


int srl(unsigned x, int k) {

    /* safety first */

    size_t w_count = sizeof(unsigned) << 3;

    if ((k < 0) || (k >= w_count)) {
        return x;
    }

    unsigned xsra = (int) x >> k;

    /* No more right shifts, but left shifts are allowed: */

    int mask = ((1 << (w_count - k)) - 1);
    
    return xsra & mask;
}

int sra(int x, int k) {

    /* safety first */

    size_t w_count = sizeof(int) << 3;

    if ((k < 0) || (k >= w_count)) {
        return x;
    }

    int xsrl = (unsigned) x >> k;

    /* No more right shifts, but left shifts are allowed.
       mask will be the flipped bits of the srl mask.
       Find out if x was a negative int: */
    int negative = (x & INT_MIN) && 1;

    /* Now activate or deactivate mask depending on whether
       x was negative: */
    int mask = ~((negative << (w_count - k)) - 1);

    return xsrl | mask;
}

int main() {

    // Tests:

    printf("\nFirst a quick verification that right shifts are performed "
        "arithmatically \nfor signed ints, but logically for unsigned ints:\n\n");

    int x = INT_MIN;
    printf("int x =  0x%08X\n", x);
    printf("x >> 8 = 0x%08X\n", x >> 8);

    unsigned ux = INT_MIN;
    printf("\nunsigned ux = 0x%08X\n", ux);
    printf("ux >> 8 =     0x%08X\n", ux >> 8);

    printf("\nNow, let's test srl:\n");

    printf("\nsrl(0x%08X, 8) = 0x%08X\n", x, srl(x, 8));
    x = INT_MAX;
    printf("\nsrl(0x%08X, 8) = 0x%08X\n", x, srl(x, 8));
    x = -1;
    printf("\nsrl(0x%08X, 8) = 0x%08X\n", x, srl(x, 8));
    x = 0;
    printf("\nsrl(0x%08X, 8) = 0x%08X\n", x, srl(x, 8));
    x = -512;
    printf("\nsrl(0x%08X, 2) = 0x%08X\n", x, srl(x, 2));

    x = 512;
    printf("\nsrl(0x%08X, 2) = 0x%08X\n", x, srl(x, 2));


    printf("\nNow, let's test sra:\n");

    x = INT_MIN;
    printf("\nsra(0x%08X, 8) = 0x%08X\n", x, sra(x, 8));
    x = INT_MAX;
    printf("\nsra(0x%08X, 8) = 0x%08X\n", x, sra(x, 8));
    x = -1;
    printf("\nsra(0x%08X, 8) = 0x%08X\n", x, sra(x, 8));
    x = 0;
    printf("\nsra(0x%08X, 8) = 0x%08X\n", x, sra(x, 8));
    x = -512;
    printf("\nsra(0x%08X, 2) = 0x%08X\n", x, sra(x, 2));

    x = 512;
    printf("\nsra(0x%08X, 2) = 0x%08X\n", x, sra(x, 2));

    printf("\n");

    return 0;
}