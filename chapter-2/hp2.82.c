#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/*

For func_A, if x is INT_MIN, then -INT_MIN will be 
UNDEFINED BEHAVIOR.

However, if we compile it with the option "-fwrapv", then 
it causes signed integer overflow to wrap, which makes 
-INT_MIN to equal INT_MIN, which then causes func_A to 
return 0.

If we do not specify this option on my local computer,
the compiler optimized the expression behind the scenes,
and I wasn't able to get func_A to return 0 unless I 
moved (-x) to the int variable neg_x, and the same for
y. In this case, the optimizations didn't happen and I 
was able to get 0 by passing in INT_MIN.

$ gcc -fwrapv -o hp2.82 hp2.82.c chapter2.c

In all cases except for those mentioned above for
INT_MIN, func_A returns 1.

*/
int func_A(int x, int y) {

    // printf("-x = %d\n", -x);
    // printf("-y = %d\n", -y);
    // printf("(x < y) = %d\n", (x < y));

    // printf("((-x) > (-y)) = %d\n", ((-x) > (-y)));
    // int neg_x = -x;
    // int neg_y = -y;

    return ((x < y) == (-x > -y));
}


/*

For func_B, if there is no overflow involved, 

(x + y) << 4 = 16(x + y) = 16x + 16y

And:

(16x + 16y) + y - x = 17y + 15x

So this will always return 1. If integer overflow occurs,
it will happen for both

(((x + y) << 4) + y - x)

and 

(17 * y + 15 * x)

So it will still return 1.

*/
int func_B(int x, int y) {
    return ((((x + y) << 4) + y - x) == (17 * y + 15 * x));
}


/*

func_C will always return 1, because:

1. Principle

When you flip the bits of any signed number, the result is the negation
of that number, minus 1.

For example, if you have a 4 bit signed number:

0100 = 4

and flip the bits:

1011 = -5

You get -5, which is -(4) - 1

2. Derivation

~x + ~y + 1 = (-x - 1) + (-y - 1) + 1 = -x - y - 1

and 

~(x + y) = -(x + y) - 1 = -x - y - 1

Therefore

~x + ~y + 1 = ~(x + y)

*/
int func_C(int x, int y) {
    return ((~x + ~y + 1) == ~(x + y));
}

/*

func_D will always return 1. 

(ux - uy) == -(unsigned) (y - x)
-(ux - uy) == (unsigned)(y - x)
uy - ux = (unsigned) (y - x)

CS:APP, p. 90:

"The w-bit two-'s-complement sum of two numbers has the 
exact same bit-level representation as the unsigned sum."

Therefore uy - ux == (unsigned) (y - x)

*/
int func_D(int x, int y) {
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    return ((ux - uy) == -(unsigned) (y - x));
}


/*

func_E will always return 1, because x might lose bits 
on the first right shift, which won't be replaced by the 
subsequent left shift. If x is negative, the signed
shift is arithmetic, so the sign bit will shift right,
and then back into place.

*/
int func_E(int x, int y) {
    return ((x >> 2) << 2) <= x;
}




int main() {
    
    // Tests:

    printf("\n");

    // Seed the random number generator:
    srand( time(NULL) );

    int x = rand(), y = rand();


    printf("############################ func_A ######################\n\n");

    x = 5;

    printf("func_A(%d, %d) returns %d\n", x, y, func_A(x, y));

    /* Casually test func_A with 20 million randomly chosen numbers */
    for (int i = 0; i <= 100000000; ++i) {
        x = rand() + rand();  // overflows to give us negative numbers
        y = rand() + rand();
        if (!func_A(x, y))
            printf("\nfunc_A(%d, %d) returns %d\n", x, y, func_A(x, y));
    }

    x = INT_MIN;

    printf("\nfunc_A(%d, %d) returns %d\n", x, y, func_A(x, y));


    printf("\n############################ func_B ######################\n");

    /* Casually test func_B with 20 million randomly chosen numbers */
    for (int i = 0; i <= 10000000; ++i) {
        x = rand() + rand();  // overflows to give us negative numbers
        y = rand() + rand();
        if (!func_B(x, y))
            printf("\nfunc_B(%d, %d) returns %d\n", x, y, func_B(x, y));
    }

    x = INT_MIN;
    y = INT_MIN + 100;
    printf("\nfunc_B(%d, %d) returns %d\n", x, y, func_B(x, y));


    x = -1;
    y = INT_MIN;
    printf("\nfunc_B(%d, %d) returns %d\n", x, y, func_B(x, y));

    x = 0;
    y = INT_MIN;
    printf("\nfunc_B(%d, %d) returns %d\n", x, y, func_B(x, y));


    printf("\n############################ func_C ######################\n");

    /* Casually test func_C with 20 million randomly chosen numbers */
    for (int i = 0; i <= 1000000; ++i) {
        x = rand() + rand();  // overflows to give us negative numbers
        y = rand() + rand();
        if (!func_C(x, y))
            printf("\nfunc_C(%d, %d) returns %d\n", x, y, func_C(x, y));
    }

    x = INT_MIN;
    y = INT_MIN + 100;
    printf("\nfunc_C(%d, %d) returns %d\n", x, y, func_C(x, y));


    x = -1;
    y = INT_MIN;
    printf("\nfunc_C(%d, %d) returns %d\n", x, y, func_C(x, y));

    x = 0;
    y = INT_MIN;
    printf("\nfunc_C(%d, %d) returns %d\n", x, y, func_C(x, y));


    printf("\n############################ func_D ######################\n");

    /* Casually test func_D with 20 million randomly chosen numbers */
    for (int i = 0; i <= 10000000; ++i) {
        x = rand() + rand();  // overflows to give us negative numbers
        y = rand() + rand();
        if (!func_D(x, y))
            printf("\nfunc_D(%d, %d) returns %d\n", x, y, func_D(x, y));
    }

    x = INT_MIN;
    y = INT_MIN + 100;
    printf("\nfunc_D(%d, %d) returns %d\n", x, y, func_D(x, y));


    x = -1;
    y = INT_MIN;
    printf("\nfunc_D(%d, %d) returns %d\n", x, y, func_D(x, y));

    x = 0;
    y = INT_MIN;
    printf("\nfunc_D(%d, %d) returns %d\n", x, y, func_D(x, y));


    printf("\n############################ func_E ######################\n");

    /* Casually test func_D with 20 million randomly chosen numbers */
    for (int i = 0; i <= 10000000; ++i) {
        x = rand() + rand();  // overflows to give us negative numbers
        y = rand() + rand();
        if (!func_E(x, y))
            printf("\nfunc_E(%d, %d) returns %d\n", x, y, func_E(x, y));
    }

    x = INT_MIN;
    y = INT_MIN + 100;
    printf("\nfunc_E(%d, %d) returns %d\n", x, y, func_E(x, y));


    x = -1;
    y = INT_MIN;
    printf("\nfunc_E(%d, %d) returns %d\n", x, y, func_E(x, y));

    x = 0;
    y = INT_MIN;
    printf("\nfunc_E(%d, %d) returns %d\n", x, y, func_E(x, y));

    printf("\n");

    return 0;
}