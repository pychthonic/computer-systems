#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/* 



*/


/* 
Instead of assuming u2f, I wrote a function for it.
*/

float u2f(unsigned u) {
    float return_val;
    unsigned char* uptr = (unsigned char*) &u;
    unsigned char* fptr = (unsigned char*) &return_val;


    for (int i = 0; i < sizeof(float); ++i) {
        *(fptr + i) = *uptr;
        uptr++;
    }
    printf("return_val bits at end of u2f:\n");
    show_bits((byte_pointer) &return_val, sizeof(return_val));


    return return_val;
}


float fpwr2(int x) {
    /* Result exponent and fraction */

    unsigned exp, frac;
    unsigned u;

    int shift_count;

    if (x < -23) {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < 0) {
        /* Denormalized result. */
        exp = 0;
        //frac = ((1 << 22) >> (unsigned) (-x));
        frac = 1 << 23;
        shift_count = -x;
        frac = frac >> shift_count;


        printf("\nfrac bits for x = %d:\n", x);
        show_bits((byte_pointer) &frac, sizeof(frac));

    } else if (x < 127) {
        /* Normalized result. */
        exp = x + 127 ;
        frac = 0;
    } else {
        /* Too big. Return +inf. */
        exp = 127;
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = ((exp << 23) | frac);
    
    printf("u bits before u2f call:\n");
    show_bits((byte_pointer) &u, sizeof(u));

    /* Return as float */
    return u2f(u);
}


int main() {
    
    // Tests:

    float f;

    // for (int x = -25; x < 2; ++x) {
    //     printf("\n########################\n\n");
    //     f = fpwr2(x);
    //     printf("\nf bits in main of fptwr2(%d):\n", x);
    //     show_bits((byte_pointer) &f, sizeof(f));
    //     printf("\nfpwr2(%d) = %f\n", x, f);
    //     printf("\n###############\n");
    // }
    
    f = 0.125;
    show_bits((byte_pointer) &f, sizeof(f));
    printf("\nf = %f\n", f);

    printf("\n");

    return 0;
}
