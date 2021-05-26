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
 * 10   addq %rcx, %rdx     ; rdx += rcx
 * 11   movq %rax, (%rdi)   ; store low-order bits of 
 * 12   movq %rdx, 8(%rdi)  ; move high-order bits stored in rdi to memory address pointed to by rdi plus 8 bytes.
 * 13   ret
 *
*/


/* TO BE CONTINUED -- TRYING TO REASON OUT WHY LINES 6 AND 7 AND DOING WHAT THEY'RE DOING...
 * Why multiply x by y's sign bits, and vice versa?
 */

int main() {
    

    return 0;
}
