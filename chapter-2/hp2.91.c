#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"



/* 

A.

0x40490FDB in bits:

4    0    4    9    0    F    D    B 
0100 0000 0100 1001 0000 1111 1101 1011

Sign bit: 0
Exp bits: 1000 0000
Frac bits: 100 1001 0000 1111 1101 1011

Bias = 127
E = 128 - 127 = 1

2^E = 2

M =           1.100 1001 0000 1111 1101 1011

V = M * 2^E = 110.0 1001 0000 1111 1101 1011


B.

22/7 = 3 + 1/7

11.???..??

1/7 as decimal fraction = 0.142857142857...142857 
1/7 as binary fraction  = 0.001001001...001

22/7 as binary fraction = 11.001001...001

whoop, it's 9am so time for work.



*/




int main() {
    
    // Tests:

    float x = 1.0/7;

    printf("x = %.30f\n", x);

    show_bits((byte_pointer) &x, sizeof(x));

    
    printf("\n");

    return 0;
}
