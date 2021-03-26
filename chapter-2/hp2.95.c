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

/* 

Compute 0.5*f. If f is NaN, return f. 

This one is the "division" version of hp2.95. It will be similar. I think the
major difference will be accounting for "rounding to even", as well as moving
the boundaries of the cases to cover the ground differently.


Breaking different scenarios down case by case:

1/ Normalized values without min exp:

Subtract one from exp.

2/ Normalized values with min exp:

Number will become denormalized. Subtract one from exp to make it zero.
Right shift frac bits by one, round to even.

3/ Denormalized values:

Right-shift frac bits by 1, and rounding to even.

*/
float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = ((f >> 23) & 0xFF);
    unsigned frac = f & 0x7FFFFF;
    
    /* Test for NaN */
    if (( exp == 255 ) && ( frac != 0 )) {
        return f;
    }

    if ((exp > 0) && (exp != 1)) {
        exp -= 1;
    } else if (exp == 1) {
        exp = 0;
        frac >>= 1;
    } else if (exp == 0) {
        if (frac & 3 == 3) {
            frac += 1;
        }
        frac >>= 1;
    }

    return ((sign << 31) | (exp << 23) | frac);
}



int main() {
    
    // Tests:

    float f, f_half, f_half_computer;

    float_bits fb, fb_half;

    float_bits* f_ptr;


    for (fb = 0; fb <= 10; ++fb) {
        
        fb_half = float_half(fb);

        f = u2f(fb);
        f_half_computer = f * 0.5;

        f_ptr = (float_bits*) &f_half_computer;

        if ((fb_half != *f_ptr) && !isnan(f)) {
            printf("\n###########################################\n");
            printf("\n\nWhoops:\n\nfb: %u, *f_ptr = %u\n", fb, *f_ptr);
            printf("\nfb_half         = %.50f\nf_half_computer = %.50f\n", *(float*) &fb_half, f_half_computer);

            printf("\nfb bits:\n");
            show_bits((byte_pointer) &fb, sizeof(fb));

            printf("\nfb_half bits:\n");
            show_bits((byte_pointer) &fb_half, sizeof(fb_half));

            printf("\nf bits:\n");
            show_bits((byte_pointer) &f, sizeof(f));
            printf("\n*f_ptr bits:\n");
            show_bits((byte_pointer) f_ptr, sizeof(fb_half));

            printf("\n");


        }
        if (isnan(f) && (fb != fb_half)) {
            printf("Whoops:\nfb: %u\n", fb);
        }
        
        /* Avoid infinite loop caused by unsigned overflow: */
        if (fb == UINT_MAX) {
            break;
        }
    }

    printf("\n");

    return 0;
}
