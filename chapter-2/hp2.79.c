#include <stdio.h>

#include "chapter2.h"



/* Multiply x by 3, then divide by 4 */
int mul3div4(int x) {
       int result = (x << 1) + x;
       int bias = (((result < 0) << 2) - ((result < 0) && 1));
       return ((result + bias) >> 2);
}


int main() {
    
    // Tests:

    int x = 5;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = -5;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = 55;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = 52342;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = -52342;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = INT_MAX;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = 0;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = INT_MIN;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    x = -1;
    printf("\n%d * 3 / 4 =   %d\nmul3div4(%d) = %d\n", x, x * 3 / 4, x, mul3div4(x));

    printf("\n");

    return 0;
}