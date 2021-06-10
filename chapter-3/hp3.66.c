/*
 *
 * Consider the following source code, where NR and NC are macros declared
 * with #define that compute the dimensions of array A in terms of
 * parameter n. This code computes the sum of the elements of column j of
 * the array.
 *
 */

long sum_col(long n, long A[NR(n)][NC(n)], long j) {
	long i;
	long result = 0;
	for (i = 0; i < NR(n); i++)
		result += A[i][j];
	return result;
}

/* GCC generates this assembly:
 *
 * 1  sum_col:
 * 2    leaq 1(,%rdi,4), %r8		; r8 = 4n + 1
 * 3    leaq (%rdi,%rdi,2), %rax	; rax = 3n
 * 4    movq %rax, %rdi			; rdi = rax = 3n
 * 5    testq %rax, %rax		 
 * 6    jle .L4				; if rax <= 0 goto .L4
 * 7    salq $3, %r8			; r8 *= 8, so r8 at this point is 8(4n+1)
 * 8    leaq (%rsi,%rdx,8), %rcx	; rcx = 8j + &A
 * 9    movl $0, %eax			; rax = 0
 * 10   movl $0, %edx			; rdx = 0
 * 11 .L3:
 * 12   addq (%rcx), %rax		; rax += *rcx
 * 13   addq $1, %rdx			; rdx += 1
 * 14   addq %r8, %rcx			; rcx += r8
 * 15   cmpq %rdi, %rdx
 * 16   jne .L3				; if rdx != rdi, goto .L3
 * 17   rep; ret			; return rax
 * 18 .L4:
 * 19   movl $0, %eax
 * 20   ret				; return 0
 *
 * Reverse engineer the assembly to get the values of macros NR and NC.
 *
 */

/*
 * In line 5, the assembly tests whether rax is below 0, and to skip the for loop
 * altogether if so. Therefore, rdi after line 4 must hold NR(n), which is (3 * n).
 *
 * In line 14, the loop progresses by adding the number of bytes in (NC(n) * 8),
 * which from line 2 we know is 8(4n + 1). Therefore, NC(n) = (4 * n + 1).
 *
 */


int main() {
    	return 0;
}
