#include <stdio.h>

#include "chapter2.h"



int int_shifts_are_arithmetic() {
    /* Set x to INT_MIN, which will have only the most
    significant bit set, i.e. 0x8000...0000
    */
    int x = INT_MIN;

    /* Shift the most significant bit into the least
    significant position:
    */
    x = x >> ((sizeof(int) << 3) - 1);
    

    /* If the shift was performed arithmatically, x will
    now equal -1: 
    */
    return x == -1;
}

int main() {
    // Tests:

    if (int_shifts_are_arithmetic()) {
        printf("Right shifts are arithmatic.\n");
    } else {
        printf("Right shifts are logical.\n");
    }

    return 0;
}