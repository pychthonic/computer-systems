#include <stdio.h>
#include <assert.h>

/* Reverse-engineer the following assembly code generated by gcc:
 *
 * decode2:
 *  subq %rdx, %rsi
 *  imulq %rsi, %rdi
 *  movq $rsi, %rax
 *  salq $63, %rax
 *  sarq $63, %rax
 *  xorq %rdi, %rax
 *  ret 
*/

extern long decode2_asm(long x, long y, long z);

long decode2(long x, long y, long z) {
    long val = y - z;
    return (val & 1) ^ (x * val);
}

int main() {
    
    long x = 450, y = 321, z = -6203;
    long a = decode2(x, y, z);
    long b = decode2_asm(x, y, z);
    
    printf("\ndecode2 got %ld, original assembly got %ld\n", a, b);
    
    assert(decode2(x, y, z) == decode2_asm(x, y, z));

    return 0;
}
