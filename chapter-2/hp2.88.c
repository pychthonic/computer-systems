#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/* 

Format A:

1 sign bit
k = 5 exponent bits. Bias = 15
n = 3 fraction bits

Format B:

1 sign bit
k = 4 exponent bits. Bias = 7
n = 4 fraction bits.


   Format A                         Format B
   Bits             Value           Bits                Value
1/ 1 01111 001      -9/8            1 0111 0010         -9/8
2/ 0 10110 011      176             0 1110 0110         176
3/ 1 00111 010      -5/1024         1 0000 0101         -5/1024
4/ 0 00000 111      7/131072        0 0000 0001         1/1024
5/ 1 11100 000      -8192           1 1110 1111         -248
6/ 0 10111 100      384             0 1111 0000         +inf



Scratch work / explanations for above:

1/

Format A:

E = 15 - 15 = 0
2^E = 1

f = 1/8
M = 9/8

V = 9/8

Format B:
Bias = 7

f = 1/8 = 0010
M = 9/8

E = 0
e = 0 + Bias = 7 = 0111



2/

Format A:

0 10110 011

e = 22
E = 22 - 15 = 7

f = 3/8
M = 11/8

V = 11/8 * 2^7 = 11/8 * 128 = 1408/8 = 704/4 = 352/2 = 176

Format B:


10110000

f = 0110 = 3/8
M = 11/8

176 = 2^E * 11/8
1408 = 2^E * 11
2^E = 128

E = 7

7 = e - 7

e = 14

Bits: 0 1110 0110 



3/

Format A bits:  1 00111 010

E = 7 - 15 = -8

f = 1/4
M = 5/4

V = (5/4 * 2^-8) = 5/4 * 1/256 = 5/1024, or -5/1024 with sign bit

Format B:

We will have to make the number denormalized to get close to -5/1024

I'm going to start with

f = 0100 = 1/4
M = 1/4

With 0100 for f, we would have a V of:

V = -1 * 1/4 * 2^(-6) = -1 * 1/4 * 1/64 = -1/256 = -4/1024

This means we should set the least significant bit of f to get -5/1024:

f = 0101 = 5/16
M = 5/16

V = -1 * 5/16 * 1/64 = -5/1024






4/

Bits: 0 00000 111

This is a denormalized value.

f = 7/8
M = 7/8

E = 1 - 15 = -14

2^E = 1/16384

V = 1/16384 * 7/8 = 7/131072

Format B:

We established in #3 that denormalized numbers for format B have 
increments of 1/1024

7/131072 is not convertible into a multiple of 1/1024 so we will have to
round up for this one.

What is the smallest number greater than 7/131072 that is a multiple of 1/1024?

Clearly, it is 1/1024, since 1/1024 > 7/131072

So we want a V of 1/1024

1/1024 has the format B bit sequence:

V = 0 0000 0001



5/

Bit sequence 1 11100 000

f = 0
M = 1

e = 28
E = 28 - 15 = 13

2^E = 8192

V = -8192


Format B:

The lowest negative number we can get with format B is:

1 1110 1111

E = 14 - 7 = 7

which is -1 * 31/16 * 128 = -248

So rounding up toward positive infinity, V for format B becomes -248



6/

Bit sequence: 0 10111 100

Format A:

f = 1/2
M = 3/2

e = 23

E = 23 - 15 = 8

2^E = 256

V = 256 * 3/2 = 384

Format B:

A corollary of 5/ was the the largest value format B can hold that is less
than infinity is 248

So to round up toward +inf, we get +inf:

0 1111 0000


*/



int main() {
    
    // Tests:


    printf("\n");

    return 0;
}
