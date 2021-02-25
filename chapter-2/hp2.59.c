#include <stdio.h>

#include "chapter2.h"

int combine_ints(int x, int y) {
    return (x & 0xFF) | (y & 0xFFFFFF00);
}

int main() {

    int x = 0x89ABCDEF;
    int y = 0x76543210;
    
    printf("\nx: 0x%X\n", x);

    printf("\ny: 0x%X\n", y);


    int new_int = combine_ints(x, y);

    printf("\nnew int generated: 0x%X\n\n", new_int);



    return 0;
}