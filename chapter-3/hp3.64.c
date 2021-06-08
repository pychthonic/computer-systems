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
 * store_ele:
 * leaq (%rsi,%rsi,2), %rax
 * leaq (%rsi,%rax,4), %rax     ; rax = (3 * j)*4 + j = 13 * j
 * movq %rdi, %rsi
 * salq $6, %rsi	        ; j = i * 64
 * addq %rsi, %rdi		; i += (i * 64)
 * addq %rax, %rdi		; i += rax
 * addq %rdi, %rdx		; k += i
 * movq A(,%rdx,8), %rax	; 
 * movq %rax, (%rcx)
 * movl $3640, %eax
 * ret
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
 * For array A[R][S][T],
 * 
 * 
 *
 *
 */

int main() {
    	return 0;
}
