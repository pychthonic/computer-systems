/*
 *
 * Fig (a) shows the code for a function that is similar to function vfunct (Figure 3.43(a)).
 * We used vfunct to illustrate the use of a frame pointer in managing variable-size stack
 * frames. The new function aframe allocates space for local array p by calling library
 * function alloca. This function is similar to the more commonly used function malloc,
 * except that it allocates space on the run-time stack. The space is automatically deallocated
 * when the executing procedure returns.
 *
 * Fig (b) shows the part of the assembly code that sets up the frame pointer and allocates
 * space for local variables i and p. It is very similar to the coresponding code for vframe.
 * Let us use the same notation as in Problem 3.49: The stack pointer is set to values s1
 * at line 4 and s2 at line 7. The start address of array p is set to value p at line 9.
 * Extra space e2 may arise between s2 and p, and extra space e1 may arise between the end of
 * array p and s1.
 *
 * A. Explain, in mathematical terms, the logic in the computation of s2.
 * 
 * &s2 = rsp - (((8*n) + 30) && -16)
 *
 * If n is 1, &s2 = 38 && -16 = 32, for 8 bytes of array space plus padding
 *
 * If n is 2, &s2 = 46 && -16 = 0010 1110 && 1111 0000 = 32, for 16 bytes of array space
 *
 * If n is 3, &s2 = 54 && -16 = 0011 0110 && 1111 0000 = 48, for 24 bytes of array space
 *
 * If n is 4, &s2 = 62 && -16 = 0011 1110 && 1111 0000 = 48, for 32 bytes of array space
 *
 * So, if n is odd, &s2 = rsp - (8*n) - 24
 *
 * If n is even, &s2 = rsp - (8*n) - 16
 *
 *
 * B. Explain in mathematical terms the logic in the computation of p.
 *
 * p = (&s2 + 15) && -16
 *
 * p will be the address of s2, rounded up by 16.
 *
 *
 * C. Find values of n and s1 that lead to minimum and maximum values of e1.
 *
 * For maximum e1:
 *
 * n will be an odd number, since that will create 24 bytes of padding instead of
 * 16.
 *
 * s1 will be a multiple of 16, so that p will not round up any bytes from s2.
 *
 * For minimum e1: 
 *
 * n will be an even number, since that will create 16 bytes of padding instead of
 * 24.
 *
 * &s1 will be rbp - 15. I don't see how this is possible, given that the compiler
 * seems to always pads the variables inside memory so that they are multiples of 16
 * or 32, but theoretically, rbp - 15 would produce the minimum e1.
 *
 *
 * D. What alignment properties does this code guarantee for the values of s2 and p?
 *
 * s2 will be the lowest multiple of 16 that is less than or equal to a multiple of
 * 16 less than s1, so the lowest multiple of 16 less than or equal to (8 * n) less
 * than s1, aligned with s1 instead of memory address 0.
 * 
 *
 * p will be a muliple of 16 in memory, that is, a multiple of 16 aligned with memory
 * address 0.
 * 
 *
 *
 */

/* (a) */

#include <alloca.h>

long aframe(long n, long idx, long *q) {
	long i;
	long **p = alloca(n * sizeof(long *));
	p[0] = &i;
	for (i = 1; i < n; i++) {
		p[i] = q;
	}
	return *p[idx];
}


/* (b) */

/*
 * 1  aframe:
 * 2	pushq %rbp
 * 3	movq %rsp, %rbp
 * 4	subq $16, %rsp
 * 5	leaq 30(,%rdi, 8), %rax
 * 6	andq $-16, %rax
 * 7	subq %rax, %rsp
 * 8	leaq 15(%rsp), %r8
 * 9	andq $-16, %r8
 *
 */


int main() {
    	return 0;
}
