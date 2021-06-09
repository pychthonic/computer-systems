#include <stdio.h>

/*
 *
 * Consider the following source code:
 *
 */

long A[R][S][T];

long store_ele(long i, long j, long k, long *dest) {
	*dest = A[i][j][k];
	return sizeof(A);
}

/*
 * In compiling the program, GCC generates this assembly code:
 *
 * 1  store_ele:
 * 2  leaq (%rsi,%rsi,2), %rax
 * 3  leaq (%rsi,%rax,4), %rax     ; rax = (3 * j)*4 + j = 13 * j
 * 4  movq %rdi, %rsi
 * 5  salq $6, %rsi	        ; j = i * 64
 * 6  addq %rsi, %rdi		; i += (i * 64)
 * 7  addq %rax, %rdi		; i += rax
 * 8  addq %rdi, %rdx		; k += i
 * 9  movq A(,%rdx,8), %rax	; rax = (8*k)    (L = 8 since sizeof(long) = 8)
 * 10 movq %rax, (%rcx)            ; *dest = rax
 * 11 movl $3640, %eax		; sizeof(entire array) = 3640
 * 12 ret				; return 3640
 *
 * A. Extend Equation 3.1 from two dimensions to three to provide a formula for
 * the location of array element A[i][j][k].
 *
 * For an array declared as:
 *
 * element_t D[R][C],
 *
 * Equation 3.1 applies to any element in D with regards to that element's
 * address:
 * 
 * &D[i][j] = &D + L(C*i + j), where L is the size of data type T in bytes.
 *
 * I found it useful to use E[A][R][C] instead of A[R][S][T], so I could keep
 * rows, columns, and aisles in my head.
 *
 * For an array declared as:
 *
 * element_t E[A][R][C]
 *
 * Where A stands for Aisle, R for Row and C for Column, the address of any
 * element in E is:
 *
 * &E[i][j][k] = &E + L((R*C)*i + C*j + k), where L is sizeof(element_t).
 *
 *
 * B. Use reverse engineering to determine the values of R, S, and T based on the
 * assembly.
 * 
 * Rewriting our formula using the relevant variable names from the book, we have:
 *
 * &A[i][j][k] = &A + L((S*T)*i + T*j + k), where L is sizeof(element_t).
 * 
 * For array A[R][S][T],
 * 
 * From lines 2-3, j is multiplied by 13, so T = 13
 *
 * From lines 4-6, i is multiplied by 65. So S*T = 65, and since T = 13, S = 5
 *
 * Since the total size of the 3-D array is 3640, 3640 = 8(5 * 13 * R), so
 * R = 7
 *
 */

int main() {
    	return 0;
}
