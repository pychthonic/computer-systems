#include <stdio.h>
#include <inttypes.h>

/* I wrote this out for the purpose of debugging it with gdb to 
 * confirm that the 128-bit numbers were appearing as I thought
 * they would in memory after they were stored behind the
 * *dest ptr address. Here is a copy of the gdb output
 * demonstrating this:
 *
 *
 * (gdb) disass
 * Dump of assembler code for function store_uprod:
 *    0x0000555555555149 <+0>:  endbr64 
 *    0x000055555555514d <+4>:   mov    %rsi,%rax
 *    0x0000555555555150 <+7>:    mul    %rdx
 *    0x0000555555555153 <+10>:    mov    %rax,(%rdi)
 *    0x0000555555555156 <+13>: mov    %rdx,0x8(%rdi)
 * => 0x000055555555515a <+17>:  retq
 * (gdb) p/x $rax
 * $21 = 0xf579bdf579bdf578
 * (gdb) p/x $rdx
 * $22 = 0x1
 * (gdb) x/16b $rdi
 * 0x7fffffffdf20:  0x78    0xf5    0xbd    0x79    0xf5    0xbd    0x79    0xf5
 * 0x7fffffffdf28:  0x01    0x00    0x00    0x00    0x00    0x00    0x00    0x00
 * 
 *
 * ...It's beautiful isn't it?
 *
 *        #iykyk
 *
 */


typedef unsigned __int128 uint128_t;

void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
    *dest = x * (uint128_t) y;
}

int main() {
    uint64_t x = 0xFABCDEFABCDEFABC, y = 2;
    uint128_t product;
    uint128_t *big_ptr = &product;

    store_uprod(big_ptr, x, y);

    return 0;
}
