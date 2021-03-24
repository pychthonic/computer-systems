#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"



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

    return return_val;
}

/* Takes an int x and returns float 2^x
After finally getting it right, it looks simple, but this took several
hours to figure out and get the bounds exactly right. I verified the
numbers with an online high precision calculator. */
float fpwr2(int x) {
    /* Result exponent and fraction */

    unsigned exp, frac;
    unsigned u;

    int shift_count;

    if (x < -150) {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < -127) {
        /* Denormalized result. */
        exp = 0;
        frac = ((1 << 22) >> (-(x + 127)));
    } else if (x < 128) {
        /* Normalized result. */
        exp = x + 127 ;
        frac = 0;
    } else {
        /* Too big. Return +inf. */
        exp = 255;
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = ((exp << 23) | frac);

    /* Return as float */
    return u2f(u);
}


int main() {
    
    // Tests:

    float f;

    for (int x = -152; x < 130; ++x) {
        printf("\n########################\n\n");
        f = fpwr2(x);
        printf("\nf bits in main of fptwr2(%d):\n", x);
        show_bits((byte_pointer) &f, sizeof(f));
        printf("\nfpwr2(%d) = %.50f\n", x, f);
    }
    
    printf("\n");

    return 0;
}
