#include <stdio.h>

#include "chapter2.h"

#include <sys/types.h>

/* 
A. Kernighan & Ritchie write in The C Programming Language, pg 182, Appendix 7.8,
"Shift Operators": "The result [of a shift operation] is undefined if the right
operand is [...] greater than or equal to the number of bits in the left
expression's type."
Compiling code that produces undefined behavior is not compliant with the C
Standard.

*/


// int bad_int_size_is_32() {
//     int set_msb = 1 << 31;

//     int beyond_msb = 1 << 32;

//     return set_msb && !beyond_msb;
// }

int slightly_better_int_size_is_32_B() {

    /* This is for B: it will work on any machine whose ints are
    greater than or equal to 32 bits. However, it will not work
    for machines whose ints are 16 bits. The reason for this is
    that for 16 bit int machines, 4294967295 will overflow to
    65535, so the return instruction is actually executing:

    return int_max == 65535;

    which returns True.
    */

    unsigned int_max = (unsigned) -1;
    return int_max == 4294967295;
}


int another_int_size_is_32_C() {

    /* This is for problem C. It will work on any machine, 
    according to the C Standard, which guarantees int's of 
    at least 16 bits. It won't work for any machine in the
    future which has int's of more than 64 bits.

    It works because the C Standard guarantees a u_int64_t
    int of 64 bits. So if we cast the max int of the machine
    into a u_int64_t, we can be sure there will not be
    overflow, unless a regular int has more than 64 bits
    (this obviously isn't happening any time soon in 2021).
    */

    unsigned int_max = (unsigned) -1;

    u_int64_t int_64bit = int_max;


    return int_64bit == 4294967295;
}

int int_size_is_32_for_16bit() {
    /* This seems to work too. What it does is, instead of shifting 1
    left 32 bits in one go, it shifts it over 15 bits at a time:
    */

    int set_msb = 1 << 15;
    set_msb = set_msb << 15;
    set_msb = set_msb << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}


int main() {

    printf("\n");

    // Tests:
    
    //printf("bad_int_size_is_32: %d\n", bad_int_size_is_32());

    printf("slightly_better_int_size_is_32_B: %d\n", slightly_better_int_size_is_32_B());

    printf("another_int_size_is_32_C: %d\n", another_int_size_is_32_C());

    printf("int_size_is_32_for_16bit: %d\n", int_size_is_32_for_16bit());
    
    printf("\n");

    return 0;
}