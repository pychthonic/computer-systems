#include <float.h>
#include <math.h>
#include <stdio.h>


#include "chapter2.h"

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* 

Rather than using data type float, the code will use float_bits. The code may
use both int and unsigned data types, including unsigned and integer constants 
and operations. The code may not use any unions, structs, or arrays. Most
significantly, the code must not use any floating-point data types, operations,
or constants. Instead, it shoud perform the bit manipulations that implement
the specified floating-point operations.

*/

/* Compute -f. If f is NaN, return f. */
float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    /* Test for NaN */
    if (( exp == 255 ) && ( frac != 0 )) {
        return f;
    }

    return (((!sign) << 31) | (exp << 23) | frac);
}



int main() {
    
    // Tests:

    float f, f_neg, f_neg_computer;

    float_bits fb, fb_neg;

    float_bits* f_ptr;


    for (fb = 0; fb <= 4294967295; ++fb) {
        
        fb_neg = float_negate(fb);

        f = u2f(fb);
        f_neg_computer = -f;

        f_ptr = (float_bits*) &f_neg_computer;

        if ((fb_neg != *f_ptr) && !isnan(f)) {
            printf("Whoops:\nfb: %u\n", fb);
        }
        if (isnan(f) && (fb != fb_neg)) {
            printf("Whoops:\nfb: %u\n", fb);
        }
        
        /* Avoid infinite loop caused by unsigned overflow: */
        if (fb == 4294967295) {
            break;
        }
    }



    
    printf("\n");

    return 0;
}
