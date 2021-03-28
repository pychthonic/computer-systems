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
Compute (int) f.
If conversion causes overflow or f is NaN, return 0x80000000

We will take a frac, then shift it right or left until we have
the whole number we're looking for, rounding toward zero.

First, find E.

Bias = 2^7 - 1 = 127

E = exp - Bias

*/
int float_f2i(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = ((f >> 23) & 0xFF);
    unsigned frac = f & 0x7FFFFF;
    unsigned M;

    if (exp > 0) {
        M = (frac & (1 << 23));
    } else {
        return 0;
    }
    
    int E = (int) exp - 127;
    
    if (E < 0) {
        return 0;
    } else if (E > 30) {
        return 0x80000000;
    }
    
    int returned_int = frac;
    
    if (E < 24) {
        returned_int >>= (23 - E);    
    } else {
        returned_int <<= (E - 23);
    }
    
    if (sign == 1) {
        returned_int = ((~returned_int) + 1);
    }
    
    return returned_int;
}



int main() {
    
    // Tests:

    printf("\n");
    
    float f;
    

    float_bits fb;

    float_bits* f_ptr;

    int inted_float, inted_float_computer;


    for (fb = 1065000000; fb <= UINT_MAX; ++fb) {
        
        inted_float = float_f2i(fb);

        f = u2f(fb);
        inted_float_computer = (int) f;

        f_ptr = (float_bits*) &inted_float_computer;

        if ((inted_float != inted_float_computer) && !isnan(f)) {
            printf("\n###########################################\n");
            printf("\n\nWhoops:\n\nfb: %u\n", fb);
            
            

            printf("\nfb bits:\n");
            show_bits((byte_pointer) &fb, sizeof(fb));

            printf("\ninted_float bits:\n");
            show_bits((byte_pointer) &inted_float, sizeof(inted_float));

            printf("\n*inted_float_computer bits:\n");
            show_bits((byte_pointer) &inted_float_computer, sizeof(inted_float_computer));
            
            printf("\n");
            
            break;

        }
        if (isnan(f) && (inted_float != 0x80000000)) {
            printf("Whoops:\nfb: %u\n", fb);
        }
        
        /* Avoid infinite loop caused by unsigned overflow: */
        if (fb == UINT_MAX) {
            break;
        }
    }

 

    return 0;
}
