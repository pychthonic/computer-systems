
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "chapter2.h"

/*

Compilation notes: remember to add a "-lm" option when compiling with gcc, like so:

$ gcc  -lm -o hp2.78 hp2.78.c chapter2.c

The "l" stands for "link", and the "m" stands for "math", so "link the math library".

This allows the linker to find the definition of pow(). math.h only includes the
declaration of pow(), and not the definition.

*/

/*  Divide by power of 2. Assume 0 <= k < w-1 */
int divide_power2(int x, int k) {
    
    int bias = (((x < 0) << k) - ((x < 0) && 1));

    return (x + bias) >> k;
}


int main() {
    
    // Tests:
 
    int x = 3, k = 2, y = pow(2, k);
    printf("\n              %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = -3, k = 2, y = pow(2, k);
    printf("\n              %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = -23, k = 4, y = pow(2, k);
    printf("\n             %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = -3022, k = 3, y = pow(2, k);
    printf("\n              %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));
    
    x = 52032, k = 1, y = pow(2, k);
    printf("\n              %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = -723894, k = 4, y = pow(2, k);
    printf("\n             %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = 723894, k = 4, y = pow(2, k);
    printf("\n             %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = INT_MIN, k = 5, y = pow(2, k);
    printf("\n             %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = INT_MAX, k = 5, y = pow(2, k);
    printf("\n             %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));

    x = -1, k = 4, y = pow(2, k);
    printf("\n             %d / %d = %d\n"
           "divide_power2(%d, %d) = %d\n", x, y, x / y, x, k, divide_power2(x, k));    

    printf("\n");

    return 0;
}