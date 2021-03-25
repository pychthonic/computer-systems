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

/* Compute 2*f. If f is NaN, return f. 
The instructions didn't say what to do for overflow. I'm going to make it 
overflow to infinity in either direction. 

Breaking different scenarios down case by case:

1/ Normalized values without max exp:

Add one to exp.

2/ Normalized values with max exp:

Return +/- infinity

3/ Denormalized values with 0 for most significant frac bit:

Left-shift frac bits by 1.

4/ Denormalized values with 1 for most significant frac bit:

Add one to E


*/
float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    /* Test for NaN */
    if (( exp == 255 ) && ( frac != 0 )) {
        return f;
    }


    
    return ((sign << 31) | (exp << 23) | frac);
}



int main() {
    
    // Tests:

    float f, f_twice, f_twice_computer;

    float_bits fb, fb_twice;

    float_bits* f_ptr;


    for (fb = 0; fb <= UINT_MAX; ++fb) {
        
        fb_twice = float_twice(fb);

        f = u2f(fb);
        f_twice_computer = f * 2.0;

        f_ptr = (float_bits*) &f_twice_computer;

        if ((fb_twice != *f_ptr) && !isnan(f)) {
            printf("Whoops:\nfb: %u\n", fb);
        }
        if (isnan(f) && (fb != fb_twice)) {
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
