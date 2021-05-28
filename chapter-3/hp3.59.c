#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* The following code computes the 128-bit product of two 64-bit signed
 * values x and y and stores the result in memory:
 *
 * typedef __int128 int128_t;
 * 
 * void store_prod(int128_t *dest, int64_t x, int64_t y) {
 *   *dest = x * (int128_t y);
 * }
 *
 * Gcc generates the following assembly for the computation:
 *
 *  1 store_prod:
 *  2   movq %rdx, %rax
 *  3   cqto          
 *  4   movq %rsi, %rcx
 *  5   sarq $63, %rcx 
 *  6   imulq %rax, %rcx 
 *  7   imulq %rsi, %rdx 
 *  8   addq %rdx, %rcx 
 *  9   mulq %rsi      
 * 10   addq %rcx, %rdx
 * 11   movq %rax, (%rdi)
 * 12   movq %rdx, 8(%rdi)
 * 13   ret
 *
 * Describe the algorithm used and annotate the assembly to show how
 * this algorithm is implemented.
 *
 * Solution:
 * 
 * void store_prod(int128_t *dest, int64_t x, int64_t y) {
 *   *dest = x * (int128_t y);
 * }
 *
 * 
 *
 *  1 store_prod:
 *  2   movq %rdx, %rax     ; rax = y
 *  3   cqto                ; sign extend rax to rdx:rax    so rdx is all y's sign bits
 *  4   movq %rsi, %rcx     ; rcx = x
 *  5   sarq $63, %rcx      ; rcx is all x's sign bits
 *  6   imulq %rax, %rcx    ; signed multiply rcx by rax and put result in rcx.
 *  7   imulq %rsi, %rdx    ; y = y * x
 *  8   addq %rdx, %rcx     ; rcx += rdx
 *  9   mulq %rsi           ; unsigned multiply rax by rsi, result in rdx:rax
 * 10   addq %rcx, %rdx     ; rdx += rcx -- add result of line 8 to higher order bits of result found on line 9
 * 11   movq %rax, (%rdi)   ; store low-order bits of result in memory pointed to by rdi.
 * 12   movq %rdx, 8(%rdi)  ; move high-order bits stored in rdi to memory address pointed to by rdi plus 8 bytes.
 * 13   ret
 *
*/


/* 
 * This one took me a while to really wrap my head around, and the reason is because it was
 * a poorly written description of the problem. When figuring out assembly language generated
 * by gcc, my normal thought process is that gcc chose this code in particular for a reason,
 * whereas the purpose of this assembly code was to demonstrate that bit-level multiplying
 * follows the same rules for signed as for unsigned numbers.
 *
 * So here's the algorithm:
 * 1/ Extend both numbers to 128-bit ints by extending their sign bits into another 64-bit register.
 * 2/ Multiply the lower 64 bits of x by the upper 64 bits of y. 
 * 3/ Multiple the lower 64 bits of y by the upper 64 bits of x.
 * 4/ Add these two products together.
 * 5/ Use UNSIGNED multiply to find x * y and put the result in a 128-bit sequence of memory.
 * 6/ Add the result found in #4 to the upper 64-bits of the 128-bit product found in #5.
 *
 * I spent a good amount of time trying to figure out WHY the code was doing this. It turns out,
 * the only reason it was doing this is so that it can use mulq instead of imulq. 
 *
 * There is a much easier way to do this- just use imulq with 1 operand. To be sure there wasn't
 * a reason to use mulq for the main multiplication instead of imulq, I wrote both assembly
 * functions (included in hp3.59.s), imported them into the C code below, tested the two of them
 * against 2 million randomly chosen numbers, checked they returned identical results, and
 * then timed the two functions to make sure there wasn't some behind-the-scenes reason to use
 * mulq instead of imulq. There wasn't. The code that used less code was faster about 9 out
 * of 10 times I ran the program. I wish the problem had stated that there wasn't a specific
 * reason to use this algorithm other than to demonstrate assembly code by using a long-winded
 * way to do signed multiplication.
 *
 */

typedef __int128 int128_t;

extern void store_prod_asm1(int128_t *dest, int64_t x, int64_t y);
extern void store_prod_asm2(int128_t *dest, int64_t x, int64_t y);



int main() {
    
    clock_t start, end;
    double cpu_time_used_1 = 0, cpu_time_used_2 = 0;
    

    int64_t x, y;
    int128_t x128, y128;

    long* high_bytes = (long*) &x128;
    long* high_bytes2 = (long*) &y128;
    
    int m, n, o, p;
    
    srand( time(NULL) );
    
    /* Test the two assembly functions with two million randomly chosen numbers */
    for (int i = 0; i <= 1000000; ++i) {
        
        m = rand() + rand();
        n = rand() + rand();
        o = rand() + rand();
        p = rand() + rand();
        
        x = ((int64_t) m << 32) | (int64_t) n;
        y = ((int64_t) o << 32) | (int64_t) p;
     
        start = clock();
        store_prod_asm1(&x128, x, y);
        end = clock();
        cpu_time_used_1 += ((double) (end - start));
        
        high_bytes = (long*) &x128;
        high_bytes++;
        
        start = clock(); 
        store_prod_asm2(&y128, x, y);
        end = clock();
        cpu_time_used_2 += ((double) (end - start));
        
        high_bytes2 = (long*) &y128;
        high_bytes2++;
        
        assert(x * y == *(long*) &y128);
        assert(*high_bytes == *high_bytes2);
    }

    printf("\nCPU time taken by asm function with more instructions: %f\n", cpu_time_used_1);
    printf("CPU time taken by asm function with less instructions: %f\n\n", cpu_time_used_2);
    
    return 0;
}
