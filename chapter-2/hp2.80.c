#include <stdio.h>

#include "chapter2.h"



/* 
Multiply x by 3/4, round toward zero. No overflow allowed.
To avoid overflow of x * 3, we first divide x by 4, then
multiply by 3.*/
int threefourths_x(int x) {
       int bias = (((x < 0) << 2) - ((x < 0) && 1));
       int result = ((x + bias) >> 2);
       return ((result << 1) + result);
}


int main() {
    
    // Tests:

    int x = 5;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = -5;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = 55;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = 52342;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = -52342;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = INT_MAX;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = 0;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = INT_MIN;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    x = -1;
    printf("\n(%d / 4) * 3 =       %d\nthreefourths_x(%d) = %d\n", x, (x / 4) * 3, x, threefourths_x(x));

    printf("\n");

    return 0;
}