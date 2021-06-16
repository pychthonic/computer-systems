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
 * &s2 = rsp - (((8*n) + 30) & -16)
 *
 * If n is 1, &s2 = 38 && -16 = 32
 *
 * If n is 2, &s = 46 && -16 = 0010 1110 && 1111 0000 = 32
 *
 * If n is 3, &s = 54 && -16 = 0011 0110 && 1111 0000 = 48
 *
 *
 *
 * B. Explain in mathematical terms the logic in the computation of p.
 *
 * p = (rsp + 15) & -16
 *
 *
 *
 * C. Find values of n and s1 that lead to minimum and maximum values of e1.
 *
 *
 *
 * D. What alignment properties does this code guarantee for the values of s2 and p?
 *
 *
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




















