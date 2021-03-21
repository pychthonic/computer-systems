#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/* 

We know that any 32-bit integer can be represented as a 64-bit double,
since a 64-bit double will have 52 bits to store the int.

So nothing changes about the number when it is first casted from
int to double.


A. (float) x == (float) dx

This is sometimes false, because not every integer can be represented exactly
as a single-precision float. For example, int x = 2147483647


B. dx - dy == (double) (x - y)

This is false for the case of integer overflow. The reason is that dx - dy
will not overflow, whereas (x - y) will overflow, and then give the overflowed
remainder to be cast into a double.

For example:

x = INT_MIN

y = 1

dx - dy          --> -2147483649
(double) (x - y) --> INT_MAX


C. (dx + dy) + dz == dx + (dy + dz)

This will always be true. No overflow will ever occur because the the most bits
that three int's added together will ever need is 34, which is well under the
52 bit threshold. We test this below.



D. (dx * dy) * dz == dx * (dy * dz)

This one will sometimes be false. This is because of rounding, and order of operations.

If dx + dy is going to overflow the 52 fraction bits, this rounding won't happen
in an equivalent way for dx * (dy * dz)

We prove this below


E. dx / dx == dz / dz

This will be False if either dx or dz is 0, which will produce Not a Number since
we're dividing by zero.

Proved below.

*/



int main() {
    
    // Tests:





    // Proof for A:

    int i1 = INT_MAX;

    double d1 = (double) i1;

    float f1 = (float) d1;

    printf("\n%f == %f --> %d\n", f1, d1, f1 == d1);


    // Proof for B:

    i1 = INT_MIN;
    d1 = (double) i1;

    int i2 = 1;
    double d2 = (double) i2;

    double d3 = d1 - d2;

    printf("\n%f == %f --> %d\n", d3, (double) (i1 - i2), d3 == (double) (i1 - i2));


    // Testing C:

    srand( time(NULL) );

    int x, y, z;


    double dx, dy, dz;

    for (int i = 0; i < 10000; ++i) {
        x = rand() - rand(), y = rand() - rand(), z = rand() - rand();
        dx = (double) x, dy = (double) y, dz = (double) z;

        if (((dx + dy) + dz) != (dx + (dy + dz))) {
            printf("\nFOUND FALSE for C: %d, %d, %d\n", x, y, z);
        }
    }


    // // Testing D:

    double dmult1, dmult2;

    for (int i = 0; i < 10; ++i) {
        x = rand() - rand(), y = rand() - rand(), z = rand() - rand();
        dx = (double) x, dy = (double) y, dz = (double) z;

        dmult1 = (dx * dy) * dz;
        dmult2 = dx * (dy * dz);

        if (((dx * dy) * dz) != (dx * (dy * dz))) {
            printf("\nFOUND FALSE for D:\nx: %d\ny: %d\nz: %d\n%f != %f\n", x, y, z, dmult1, dmult2);
        }
    }

    // Testing E:

    double ddiv1, ddiv2;


    x = 1, z = 0;
    dx = (double) x, dz = (double) z;

    ddiv1 = dx / dx;
    ddiv2 = dz / dz;

    if (ddiv1 != ddiv2) {
        printf("\nFOUND FALSE for E:\nx: %d\nz: %d\n%f != %f\n", x, z, ddiv1, ddiv2);
    }


    for (int i = 0; i < INT_MAX; ++i) {
        x = rand() - rand(), z = rand() - rand();
        dx = (double) x, dz = (double) z;

        ddiv1 = dx / dx;
        ddiv2 = dz / dz;

        if (ddiv1 != ddiv2) {
            printf("\nFOUND FALSE for E:\nx: %d\nz: %d\n%f != %f\n", x, z, ddiv1, ddiv2);
        }
    }

    printf("\n");

    return 0;
}
