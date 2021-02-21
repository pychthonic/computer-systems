#include <sys/types.h>
#include <stdio.h>

#include "showbytes.h"



int main() {
    // int y = 5;
    // printf("(int) y = %d\n", y);
    // show_bytes((byte_pointer) &y, sizeof(int));

    char num1 = -21;
    char num2 = 6;

    printf("\nchar num1: %d, hex bytes: ", num1);
    show_bytes((byte_pointer) &num1, sizeof(num1));

    printf("\nchar num2: %d, hex bytes: ", num2);
    show_bytes((byte_pointer) &num2, sizeof(num2));

    char product = num1 * num2;

    printf("\nnum1 * num2 = %d, hex bytes: ", product);
    show_bytes((byte_pointer) &product, sizeof(char));

    if ((num1 == 0) || (product / num1 == num2)) {
        printf("\nNO OVERFLOW\n");
    } else {
        printf("\nOVERFLOW\n");
    }

    printf("\nsizeof(size_t) = %lu\n", sizeof(size_t));

    printf("\n");

    return 0;
}