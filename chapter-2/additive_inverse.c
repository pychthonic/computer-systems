#include <limits.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;
void show_bits(byte_pointer start, size_t len) { printf("Bits:  ");
    unsigned int bit;
    unsigned char temp_byte;
    for (int i=0; i<len; i++) { 
        for (int j=8; j>0; j--) {
            if (j == 4) {
                printf(" ");
            }
            temp_byte = start[i] >> j - 1;
            bit = temp_byte & 1; 
            printf("%d", bit);
        }
        if ( i < len - 1 )
            printf(" | ");
    }
    printf("\n");
}

unsigned additive_inverse(unsigned x) {
    /* Returns the additive inverse of x
     */
    int i;
    for (i=0; i<UINT_MAX; i++) {
       if (i + x == 0)
          return i;
    }
    return 0;
} 

int main(int argc, char* argv[]) {
    unsigned y;
    printf("UINT_MAX = %u\n", UINT_MAX); 
    printf("Enter an unsigned int: ");
    scanf("%u", &y); 
    show_bits((byte_pointer) &y, sizeof(int));
    unsigned add_inv = additive_inverse(y);
    printf("The additive inverse of %u is %u\n", y, add_inv);
    show_bits((byte_pointer) &add_inv, sizeof(int)); 
    printf("UINT_MAX - y = %u\n", UINT_MAX - y);
    return 0;
}


