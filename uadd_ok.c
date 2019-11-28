#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_bits(byte_pointer start, size_t len) {
    printf("Bits:  ");
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

int uadd_ok(unsigned x, unsigned y){
    /* Returns 1 if two unsigned ints can be added
     * together without overflow. Otherwise returns
     * 0.
     */ 
    unsigned sum = x + y;
    printf("sum: ");
    show_bits((byte_pointer) &sum, sizeof(int)); 
    if (sum < x) 
        return 0;
    else
        return 1;
}

int main(int argc, char* argv[]) {
    unsigned y = 3000055000;
    unsigned z = 3000055000;
    printf("  y: "); 
    show_bits((byte_pointer) &y, sizeof(int));
    printf("  z: "); 
    show_bits((byte_pointer) &z, sizeof(int));
    
    int add_ok = uadd_ok(y, z);
    printf("result of uadd_ok with %u and %u: %d\n", y, z, add_ok);

    return 0;
}


