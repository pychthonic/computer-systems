#include <stdio.h>


#include "chapter2.h"

int a_func(int x) {
    return (x && 1);
}

int b_func(int x) {
    return ((x ^ -1) && 1);
}

int c_func(int x) {
    return ((x & 0xFF) && 1);
}

int d_func(int x) {
    return (((x >> ((sizeof(x) - 1) << 3)) & 0xFF) < 0xFF);
}

int main() {
    // Tests:

    printf("\nA:\n");
    printf("x = %08X: %d\n", 0, a_func(0));
    printf("x = %08X: %d\n", 1, a_func(1));
    printf("x = %08X: %d\n", -1, a_func(-1));
    printf("x = %08X: %d\n", INT_MIN, a_func(INT_MIN));
    printf("x = %08X: %d\n", INT_MAX, a_func(INT_MAX));


    printf("\nB:\n");
    printf("x = %08X: %d\n", 0, b_func(0));
    printf("x = %08X: %d\n", 1, b_func(1));
    printf("x = %08X: %d\n", -1, b_func(-1));
    printf("x = %08X: %d\n", INT_MIN, b_func(INT_MIN));
    printf("x = %08X: %d\n", INT_MAX, b_func(INT_MAX));

    printf("\nC:\n");
    printf("x = %08X: %d\n", 0, c_func(0));
    printf("x = %08X: %d\n", 1, c_func(1));
    printf("x = %08X: %d\n", -1, c_func(-1));
    printf("x = %08X: %d\n", INT_MIN, c_func(INT_MIN));
    printf("x = %08X: %d\n", INT_MAX, c_func(INT_MAX));
    printf("x = %08X: %d\n", 0xFF, c_func(0xFF));
    printf("x = %08X: %d\n", 0x55, c_func(0x55));
    printf("x = %08X: %d\n", 0xFFFFFF00, c_func(0xFFFFFF00));
    

    printf("\nD:\n");
    printf("x = %08X: %d\n", 0, d_func(0));
    printf("x = %08X: %d\n", 1, d_func(1));
    printf("x = %08X: %d\n", -1, d_func(-1));
    printf("x = %08X: %d\n", INT_MIN, d_func(INT_MIN));
    printf("x = %08X: %d\n", INT_MAX, d_func(INT_MAX));
    printf("x = %08X: %d\n", 0xFF000000, d_func(0xFF000000));
    printf("x = %08X: %d\n", 0xFF015A4A, d_func(0xFF015A4A));
    printf("x = %08X: %d\n", 0xFF, d_func(0xFF));

    return 0;
}