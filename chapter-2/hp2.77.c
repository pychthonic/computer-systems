#include <stdio.h>
#include <stdlib.h>

#include "chapter2.h"



/*  Bit-level shortcuts for multiplying by constants */

int mult_17(int x) {
    return ((x << 4) + x);
}

int mult_negative_7(int x) {
    return (((0 - x) << 3) + x); 
}

int mult_60(int x) {
    return ((x << 6) - (x << 2));
}

int mult_negative_112(int x) {
    return ((x << 4) - (x << 7));
}

int main() {
    
    // Tests:

    int x = 3;

    printf("\n%d * 17 =       %d\nmult_17(%d) --> %d\n", x, x * 17, x, mult_17(x));

    x = -872839;
    printf("\n%d * 17 =       %d\nmult_17(%d) --> %d\n", x, x * 17, x, mult_17(x));

    x = -1;
    printf("\n%d * 17 =       %d\nmult_17(%d) --> %d\n", x, x * 17, x, mult_17(x));

    x = 0;
    printf("\n%d * 17 =       %d\nmult_17(%d) --> %d\n", x, x * 17, x, mult_17(x));

    x = INT_MAX;
    printf("\n%d * 17 =       %d\nmult_17(%d) --> %d\n", x, x * 17, x, mult_17(x));

    x = INT_MIN;
    printf("\n%d * 17 =       %d\nmult_17(%d) --> %d\n", x, x * 17, x, mult_17(x));

    printf("\n##############################\n");

    x = 3;
    printf("\n%d * -7 =               %d\nmult_negative_7(%d) --> %d\n", x, x * -7, x, mult_negative_7(x));

    x = -872839;
    printf("\n%d * -7 =               %d\nmult_negative_7(%d) --> %d\n", x, x * -7, x, mult_negative_7(x));

    x = -1;
    printf("\n%d * -7 =               %d\nmult_negative_7(%d) --> %d\n", x, x * -7, x, mult_negative_7(x));

    x = 0;
    printf("\n%d * -7 =               %d\nmult_negative_7(%d) --> %d\n", x, x * -7, x, mult_negative_7(x));

    x = INT_MAX;
    printf("\n%d * -7 =               %d\nmult_negative_7(%d) --> %d\n", x, x * -7, x, mult_negative_7(x));

    x = INT_MIN;
    printf("\n%d * -7 =               %d\nmult_negative_7(%d) --> %d\n", x, x * -7, x, mult_negative_7(x));

    printf("\n##############################\n");
    
    x = 3;
    printf("\n%d * 60 =       %d\nmult_60(%d) --> %d\n", x, x * 60, x, mult_60(x));

    x = -872839;
    printf("\n%d * 60 =       %d\nmult_60(%d) --> %d\n", x, x * 60, x, mult_60(x));

    x = -1;
    printf("\n%d * 60 =       %d\nmult_60(%d) --> %d\n", x, x * 60, x, mult_60(x));

    x = 0;
    printf("\n%d * 60 =       %d\nmult_60(%d) --> %d\n", x, x * 60, x, mult_60(x));

    x = INT_MAX;
    printf("\n%d * 60 =       %d\nmult_60(%d) --> %d\n", x, x * 60, x, mult_60(x));

    x = INT_MIN;
    printf("\n%d * 60 =       %d\nmult_60(%d) --> %d\n", x, x * 60, x, mult_60(x));



    printf("\n##############################\n");

    x = 3;
    printf("\n%d * -112 =               %d\nmult_negative_112(%d) --> %d\n", x, x * -112, x, mult_negative_112(x));

    x = -872839;
    printf("\n%d * -112 =               %d\nmult_negative_112(%d) --> %d\n", x, x * -112, x, mult_negative_112(x));

    x = -1;
    printf("\n%d * -112 =               %d\nmult_negative_112(%d) --> %d\n", x, x * -112, x, mult_negative_112(x));

    x = 0;
    printf("\n%d * -112 =               %d\nmult_negative_112(%d) --> %d\n", x, x * -112, x, mult_negative_112(x));

    x = INT_MAX;
    printf("\n%d * -112 =               %d\nmult_negative_112(%d) --> %d\n", x, x * -112, x, mult_negative_112(x));

    x = INT_MIN;
    printf("\n%d * -112 =               %d\nmult_negative_112(%d) --> %d\n", x, x * -112, x, mult_negative_112(x));



    printf("\n");

    return 0;
}