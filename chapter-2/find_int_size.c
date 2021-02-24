#include <stdio.h>

int int_bits() {
    /* Returns the number of bits in an int variable
     * on the host system */ 
    unsigned arr[2]; 
    arr[0] = 0 - 1;
    arr[1] = 0;
    unsigned char* uptr;
    uptr = (char*) &arr[0];
    int bit_count = 0;
    while (*uptr != 0) {
        if (*uptr > 0){
            uptr++;
            bit_count = bit_count + 8;
        }
    }
    return bit_count;
}

int main(int argc, char* argv[]) {
    int int_size = int_bits();
    printf("int_size = %d\n", int_size); 
    return 0;
}


