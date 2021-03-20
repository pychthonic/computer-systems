#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/* 

"Half-precision" floating point format:

1 sign bit, 5 exponent bits (k = 5), 10 fraction bits (n = 10)

Bias = 15


How I got the values in the table:

Smallest val > 2:

Bits = 0??? ??00 0000 0001

f = 1/1024
M = 1 + 1/1024

E = e - Bias = e - 15

E has to equal 1, to move binary point to the right.

1 = e - 15

e = 16

Bits = 0100 0000 0000 0001

V = 2 * 1025/1024 = 2050/1024 = 1025/512




512:

Bits = 0??? ??00 0000 0000

V = 512

512 = 2^E * M

M = 1
f = 0

E = 9
E = e - Bias

9 = e - 15
e = 24

Bits = 0110 0000 0000 0000



Largest denormalized:

Bits: 0000 0011 1111 1111

Bias = 15

f = ((2^10) - 1) / (2^10)

M = ((2^10) - 1) / (2^10) = 1023/1024

E = 1 - Bias = 1 - 14 = -13

V = 1023/1024 * 2^-13 = 1023/(1024*8092)



Negative Infinity:

1111 1100 0000 0000




0x3BB0:

Bias = 15

0011 1011 1011 0000

Positive number.

e bits = 01110 = 14

E = 14 - 15 = -1

2^E = 1/2

f bits = 11 1011 0000 = 1/2 + 1/4 + 1/8 + 1/32 + 1/64 = 32/64 + 16/64 + 8/64 + 2/64 + 1/64 = 59/64

OR we can calculate f like so:

f = (16 + 32 + 128 + 256 + 512) / 1024 = 944/1024 = 472/512 = 236/256 = 118/128 = 59/64 woot!

M = 1 + 59/64 = 123/64

V = (1/2) * (123/64) = 123/128



Description                 Hex         M           E           V           D
-0          		    0x8000	   0/1024      0	        0    	    0.0
Smallest value > 2          0x4001      1025/1024   1           1025/512    2.0019531 
512                         0x6000      1024/1024   9           512         512.0
Largest denormalized        0x03FF      1023/1024   -13      1023/8286208   ~0.0001
-infinity                   0xFC00      n/a         n/a         -inf        -inf
Number with hex 0x3BB0      0x3BB0      123/64     -1         123/128       ~0.961




*/



int main() {
    
    // Tests:

    int a = 1;
    
    for (int i = 0; i < 10; ++i) { 
        a *= 2;
        printf("Leaving loop. a = %d\n", a);
    }

    printf("\nSmallest value > 2: %f\n", 1025.0/512);    

    printf("\n1023/(1024*8092) = %Le\n", 1023/(1024 * 8092));
    printf("\n");

    return 0;
}
