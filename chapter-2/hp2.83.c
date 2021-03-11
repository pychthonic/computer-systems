#include <stdio.h>
#include <sys/types.h>

#include "chapter2.h"


/* 

A.
Given 0.yyyyy....y as a binary string containing an infinite pattern of
k-bit y sequences such as

1/3 as .01010101...010101 (y = 01)
1/5 as .001100110011...0011 (y = 0011)


If Y = BTU,k(y) -- then Y is defined as the unsigned number having 
binary representation y

If we do what the hint says and consider the effect of shifting the 
binary point k positions to the right, we have:

y.yyy...y = 0.yyy...y << k = Y + 0.yyy...y
Y = (0.yyy...y << k) - 0.yyy...y = (0.yyy...y * (2^k)) - 0.yyy...y
Y = 0.yyy...y((2^k) - 1)
0.yyy...y = Y / ((2^k) - 1)


B. 
(a) 0.yyy...y = 5/((2^3) - 1) = 5/7
(b) 0.yyy...y = 6/((2^4) - 1) = 6/15 = 2/5
(c) 0.yyy...y = 19/((2^6) - 1) = 19/63





*/




int main() {
    
    // Tests:



    printf("\n");

    return 0;
}