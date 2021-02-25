#include <stdio.h>

#include "chapter2.h"

/* Return 1 when any odd bit of x equals 1; 0 otherwise. */

int any_odd_one(unsigned x) {
    return ((x & 0xAAAAAAAA) && 1);
}

int main() {

    // Tests:

    unsigned int x = INT_MAX;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));

    x = INT_MIN;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));

    x = UINT_MAX;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));

    x = 0;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));
    
    x = 5;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));

    x = -1;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));
    
    x = 1;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));
    
    x = -512;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));
    
    x = 0x55555555;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));
    
    x = 0x51155111;
    printf("any_odd_one(0x%08X) = %d\n", x, any_odd_one(x));

    return 0;
}