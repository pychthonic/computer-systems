#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/* 


A. Smallest positive denormalized of long double:

Bias = (2^14) - 1

E = 1 - ((2^14) - 1) = -(2^14) + 2 = -16384 + 2 = -16382

f = 1 / (2^64)
M = 1 / (2^64)

V = (1/(2^64))(2^-16382) = 1/(2^16446)

I don't feel like converting this number to a decimal is going to 
further my education, so I'm not going to.

It's a really small number. How small are we talking? If 1 is the
unit of a meter, and we want to imagine how small V meters is, V 
meters is basically several orders of magnitude smaller than an
atom. It's something like at the end of Men in Black when the
camera zooms out to find another universe operating on top of
the one we've been watching, but in the opposite direction, 
where we're the alien playing marbles and you zoomed into an 
atom and found more worlds happening inside the space of the atom, 
and then you measured how big a piece of dust was inside it.



Sidenote:

Largest denormalized long double:

Bias = (2^14) - 1 = 16383

E = 1 - 16383 = -16382

f = ((2^64) - 1) / (2^64)
M = ((2^64) - 1) / (2^64) = 1 - (1/(2^64))

V = (1 - (1/(2^64)))(2^-16382) = (1/(2^16382)) - (1/(2^16446))

Again, I don't feel like converting this number to a decimal is 
going to further my understanding, so I'm not going to. It's a 
really really small amount less than a really small number. 



B. 

Bias = (2^14) - 1 = 16383

E = 1 - 16383 = -16382

f = 0
M = 1

V = 1/(2^16382)


C.

Bias = (2^14) - 1

e = (2^15) - 2

E = e - Bias = ((2^15) - 2) - ((2^14) - 1) = 2^15 - 2^14 - 1 = 2^14 - 1

2^E = 2^((2^14) - 1)

f = ((2^64) - 1) / (2^64) = 1 - (1/(2^64))

M = 1 + (1 - (1/(2^64))) = 2 - (1/(2^64))

V = (M)(2^E) =  (2 - (1/(2^64)))(2^((2^14) - 1))

V meters is the indisputably proven size of one of those marbles the 
alien is tossing around. 



*/



int main() {
    
    // Tests:

    long double lf = 5.3;

    unsigned char* cp = (unsigned char*) &lf;

    printf("\nLDBL_DECIMAL_DIG: %d\n", LDBL_DECIMAL_DIG);

    printf("\n__STDC_VERSION__: %ld\n", __STDC_VERSION__);

    printf("\nsizeof(lf): %lu\n\n", sizeof(lf));
    printf("lf: %Le\n\n", lf);

    printf("I noticed the compiler pads the 6 bytes with the highest address, so ");
    printf("we'll only printf the first 10 bytes of bits:\n\n");

    show_bits((byte_pointer) &lf, 10);

    printf("\nLet's see if we can print out the smallest long double, which we found in problem A to be:\n");
    printf("\nV = 1/(2^16446)\n");
    printf("\nI don't trust pow() from the math.h library to not automatically ");
    printf("cast a long double down to a smaller data \ntype, so I'm going to use a for ");
    printf("loop.\n");

    lf = 1;

    long double divisor = 1;

    for (int i = 0; i < 16445; ++i) {
        lf /= 2;
    }

    printf("\n%.*Le\n\nsmallest long double bits:\n\n", 64, lf);

    show_bits((byte_pointer) &lf, 10);

    printf("\nBingo.\n");


    printf("\n");

    return 0;
}