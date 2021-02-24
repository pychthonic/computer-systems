#include <stdio.h>

// This program shows that integer division always rounds toward
// zero in C.

int main() {
    int num1 = 5, num2 = 9;
    printf("%d / %d = %d\n", num1, num2, num1 / num2);

    int num3 = -5;
    printf("%d / %d = %d\n", num3, num2, num3 / num2);

    printf("%d / %d = %d\n", num2, num1, num2 / num1);
    printf("%d / %d = %d\n", num2, num3, num2 / num3);

}