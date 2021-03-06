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

Compute (float) i.
For argument i, this function computes the bit-level representation of (float) i.

This is similar to hp2.96, but going in the other direction.

For all single-precision floating-point representations of whole numbers, there 
is an exact 32-bit integer representation for that number. However, this is not 
the case for all 32-bit integers. All 32-bit integers do not have an exact 
single-precision floating-point representation. This means we will have to round 
to even for some numbers.

Here are the steps we will use:

1/ Push the integer into what will become the frac portion of the float bits,
rounding to even.

2/ Calculate what the exp bits should be.

3/ Return the number.

*/
float_bits float_i2f(int i) {

    unsigned sign = 0;
    unsigned u_temp = (unsigned) i;

    unsigned lost_bits = 0;

    if (i == 0) {
        return 0;
    }

    if (i < 0) {
        sign = 1;
        u_temp = ((~u_temp) + 1);
    }

    unsigned right_shift_count = 0;

    unsigned M = u_temp;

    unsigned frac;
    int lost_bit = 0, last_lost_bit = 0, last_lost_bit_placed = 0;

    while ((M & 0xFF000000) != 0) {

        if (M & 1 == 1) {
            lost_bits = (lost_bits | (1 << right_shift_count));
            lost_bit = 1;
            last_lost_bit = 1;
        } else {
            last_lost_bit = 0;
        }

        right_shift_count += 1;
        M >>= 1;
    }

    if (M == ((1 << 24) - 1)) {
        if ((last_lost_bit) == 1) {
            M = 1;
            M <<= 23;
            right_shift_count += 1;
            last_lost_bit = 0;
        }
    }

    if (last_lost_bit == 1) {
        last_lost_bit_placed = 1 << (right_shift_count - 1);
        lost_bits = (lost_bits & (~last_lost_bit_placed));

        if (lost_bits > 0) {
            M += 1;
        } else {
            if (M & 1) {
                M += 1;
            }
        }
    }
    
    unsigned left_shift_count = 0;

    while ((M & 0x00800000) == 0) {
        left_shift_count += 1;
        M <<= 1;
    }

    frac = M & 0x007FFFFF;

    int E = 23 - left_shift_count + right_shift_count;

    unsigned exp = E + 127;

    return ((sign << 31) | (exp << 23) | frac);
}



int main() {
    
    // Tests:

    printf("\n");
    
    int i;
    float_bits fb;

    float floated_int, floated_int_computer;

    for (i = INT_MIN; i <= INT_MAX; ++i) {

        fb = float_i2f(i);
        floated_int = u2f(fb);

        floated_int_computer = (float) i;

        if ((floated_int != floated_int_computer)) {
            printf("\n###########################################\n");
            printf("\n\nWhoops:\n\ni: %d\n", i);
            
            printf("\ni bits:\n");
            show_var_bits((byte_pointer) &i, sizeof(i));

            printf("\nfloated_int bits:\n");
            show_var_bits((byte_pointer) &floated_int, sizeof(floated_int));

            printf("\nfloated_int_computer bits:\n");
            show_var_bits((byte_pointer) &floated_int_computer, sizeof(floated_int_computer));
            
            printf("\n");
            
            break;

        }
        
        /* Avoid infinite loop caused by unsigned overflow: */
        if (i == INT_MAX) {
            break;
        }
    }

 

    return 0;
}
