#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/* 

A. The number 7.0 

Bias = ((2^(k - 1)) - 1)


round(2, k) = e - ((2^(k-1)) - 1)
e = round(2, k) + ((2^(k-1)) - 1)

E = round(U2B(2), k)

f = round(.110, n)
M = 1 + round(.110, n)

V = M * (2^E)
V = (1 + round(.11, n)) * (2^(round(U2B(2), k)))

Binary representation:

0[round(2, k) + ((2^(k-1)) - 1)][round(.110, n)]

B. 

The largest odd integer that can be represented exactly:

It will have the bit pattern: 0[?????][111...1]


f = ((2^n) - 1)/(2^n)
M = 1 + (((2^n) - 1)/(2^n))



Bias = ((2^(k-1)) - 1)

E = n      --> E will have to be whatever exponent will bring the
                binary point all the way to the right, which means
                it will move over n positions.


E = e - Bias

e = n - Bias


V = (2^n)(1 + (((2^n) - 1)/(2^n)))

For a single-precision float:

V = (2^23)(1 + ((2^23) - 1)/(2^23)) = 838608(1 +(8388607/8388608))
V = 16777215






C.

Write an equation for the reciprocal of the smallest positive NORMALIZED
value.

The reciprocal of a fraction is the fraction flipped upside down.
The reciprocal of 1/6 is 6/1 and vice versa.

First, we'll find an equation for the smallest positive normalized value:

Bias = ((2^(k-1)) - 1)

e = 1
E = 1 - ((2^(k-1)) - 1) = 2 - ((2^(k-1))

f = 0
M = 1.0

V = 2^(2 - (2^(k-1)))

The reciprocal of V is:

R = 1/(2^(2 - (2^(k-1))))





Bonus: Write an equation for the reciprocal of the smallest positive DENORMALIZED
value.



First, we'll find an equation for the smallest positive DENORMALIZED value:

Bias = ((2^(k-1)) - 1)

e = 0
E = 0 - ((2^(k-1)) - 1) = 1 - ((2^(k-1))

f = 2^(-n)
M = 2^(-n)

V = (1 - ((2^(k-1)))(2^(-n))

The reciprocal of V is:

R = 1/(1 - ((2^(k-1)))(2^(-n))








*/



int main() {
    
    // Tests:

    /* 
    The following code will bruteforce the largest w-bit int (as in, a signed
    integer on the local computer it's compiled on). This is slightly different 
    from what problem 2.85B is asking for, which is the largest integer (in the 
    general sense, not specifically the data type int) that a float can describe.
    However, we proved above that the largest integer for floats is actually
    less than INT_MAX, this will still give the correct answer.
    */

    float f_max_odd_int;

    for (int i = 0; i < INT_MAX; ++i) {
        if ( ((float) i == i) && (((int) (float) i) % 2 == 1) ) {
            f_max_odd_int = (float) i;
        }
    }

    printf("f_max_odd_int: %f\n", f_max_odd_int);

    printf("f_max_odd_int bits:\n");
    show_bits((byte_pointer) &f_max_odd_int, sizeof(f_max_odd_int));

    int imax = INT_MAX;
    float fimax = (float) imax;
    printf("\nfimax: %f\n", fimax);

    printf("fimax bits:\n");
    show_bits((byte_pointer) &fimax, sizeof(fimax));

    printf("imax bits:\n");
    show_bits((byte_pointer) &imax, sizeof(imax));


    // Create smallest positive normalized value:

    float f_small;
    unsigned char* fptr = (unsigned char*) &f_small;

    *fptr = 1;
    fptr++;
    *fptr = 0;
    fptr++;
    *fptr = 0;
    fptr++;
    *fptr = 0;

    printf("\nf_small: %f\n", f_small);

    show_bits((byte_pointer) &f_small, sizeof(f_small));

    float f_small2 = FLT_MIN;

    printf("\nf_small2: %f\n", f_small2);

    show_bits((byte_pointer) &f_small2, sizeof(f_small2));


    printf("\n");

    return 0;
}