#include <stdio.h>

#include "chapter2.h"

/*  Generate mask indicating leftmost 1 in x.

    This is not the best way to do it but it works.

    It also doesn't work yet but I'm calling it a day and pushing the code for now.
    TBC...
    
*/

int leftmost_one(unsigned x) {
    size_t w_count = sizeof(unsigned) << 3;
    size_t bit_count = 0;

    int inty_left_bits = (((unsigned int) ((unsigned short) x)) != x);

    unsigned short shorty = (unsigned short) (x >> (inty_left_bits << 4));
    
    printf("\nAfter first pass, inty_left_bits = %d, shorty = %d\n", inty_left_bits, shorty);

    int shorty_left_bits = (((unsigned short) ((unsigned char) shorty)) != shorty);

    unsigned char bytey = (unsigned char) (shorty >> (shorty_left_bits << 3));

    printf("\nAfter two passes, shorty_left_bits = %d, bytey = %d\n", shorty_left_bits, bytey);

    int bytey_left_bits = (bytey != (bytey & 0x0F));

    unsigned char nibble = bytey >> (bytey_left_bits << 2);

    printf("\nAfter three passes, bytey_left_bits = %d, nibble = %d\n", bytey_left_bits, nibble);

    int nibble_left_bits = (nibble != (nibble & 0x03));

    unsigned char halfnibble = nibble >> (nibble_left_bits << 1);

    printf("\nAfter four passes, nibble_left_bits = %d, halfnibble = %d\n", nibble_left_bits, halfnibble);

    return ((((((1 << (halfnibble & 1)) << ((halfnibble & 2))) << (nibble_left_bits << 1)) << (bytey_left_bits << 2)) << (shorty_left_bits << 3)) << (inty_left_bits << 4));


    }

int main() {

    printf("\n");

    // Tests:
    
    unsigned x = 8223;

    unsigned mask = leftmost_one(x);

    printf("\nx    bits: ");
    show_bits((byte_pointer) &x, sizeof(x));

    printf("Mask bits: ");
    show_bits((byte_pointer) &mask, sizeof(mask));

    printf("\n");

    return 0;
}