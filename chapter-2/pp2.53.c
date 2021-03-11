#include <stdio.h>

#include "chapter2.h"

#include "math.h"

// #define POS_INFINITY 0x0000 0000 0000 F07F
#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)

int main() {
    double d1 = 5;

    long int i1 = 0x7FF0000000000000;
    unsigned char* dptr = (unsigned char*) &d1;
    unsigned char* iptr = (unsigned char*) &i1;
    for (int i = 0; i < 8; ++i) {
        *(dptr) = *(iptr + i);
        dptr++;
    }

    printf("\n\nd1: %f\n", d1);
    show_bits((byte_pointer) &d1, sizeof(d1));

    printf("\ni1 bits:\n");
    show_bits((byte_pointer) &i1, sizeof(i1));


    d1 = INFINITY;

    printf("\n\nd1: %f\n", d1);
    show_bits((byte_pointer) &d1, sizeof(d1));


    d1 = POS_INFINITY;

    printf("\n\nd1: %f\n", d1);
    show_bits((byte_pointer) &d1, sizeof(d1));

    d1 = NEG_INFINITY;

    printf("\n\nd1: %f\n", d1);
    show_bits((byte_pointer) &d1, sizeof(d1));

    d1 = NEG_ZERO;

    printf("\n\nd1: %f\n", d1);
    show_bits((byte_pointer) &d1, sizeof(d1));

    printf("\n\n");
    return 0;
}