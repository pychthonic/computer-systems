#include <stdio.h>
#include <string.h>

int gimme_a_mask(int byte_mask_count) {
    int i;
    int mask = 0;
    for (i=0; i<byte_mask_count; i++) {
        int next_nibble = (mask + 1) * 0xf;
        mask = mask | next_nibble;
    }
    mask = ~mask;
    return mask;
}


int main () {
    int byte_mask_count;
    int a, mask;
    printf("Enter an int: ");
    scanf("%d", &a);
    printf("That number in hex is: %x.\nHow many of its least significant nibbles do you want to mask? ", a);
    scanf("%d", &byte_mask_count);
    mask = gimme_a_mask(byte_mask_count);
    a = a & mask;
    printf("Here's your masked number: 0x%x\n", a); 
    return 0;
}
