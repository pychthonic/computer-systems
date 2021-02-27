#include <stdio.h>

#include "chapter2.h"

/* This problem was a fun one. I had to think about it for 10 
   minutes to figure out a plan.
   
   Return 1 when x contains an odd number of 1s; 0 otherwise.
*/

int odd_ones(unsigned x) {
    size_t w_count = sizeof(unsigned) << 3;
    size_t bit_count = 0;

    /* 12 or less arithmetic, bitwise and logical operations after
       this line.
       
       XOR'ing the most significant 2 bytes against the
       least significant 2 bytes will leave us with a short
       in the least significant 2 bytes that has the same
       "oddness" as the original four bytes. We cast the result
       into a short in order to get rid of the most significant
       2 bytes:
    */
    unsigned short shorty = x ^ (x >> 16);

    /* Same thing as above, but going from unsigned short to 
       unsigned char:
    */

    unsigned char bytey = shorty ^ (shorty >> 8);
    
    /* Down to a nibble this time, and we have to AND out the
       most significant nibble, so the next line will take
       3 instructions:
    */

    bytey = ((bytey & 0xF) ^ (bytey >> 4));

    /* Same as last time but after this next instruction
       we have two bits left.
    */

    bytey = ((bytey & 0x3) ^ (bytey >> 2));

    /* Now we just have to check whether the remaining number 
       is either 1 or 2, since if the remaining number is 0
       or 3, it means the number has an even number of bits:
    */

    return (bytey == 1) || (bytey == 2);
}

int main() {

    // Tests:

    unsigned x = 5;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 6;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 7;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = INT_MAX;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));
    
    x = INT_MIN;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 0;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 1;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = -1;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 7;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 523502;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 5221;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = -923;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    x = 3521532;
    printf("\nx = %d; odd_ones(0x%08X) = %d\n", x, x, odd_ones(x));
    show_bits((byte_pointer) &x, sizeof(x));

    printf("\n");

    return 0;
}