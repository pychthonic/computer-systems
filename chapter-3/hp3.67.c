#include <stdio.h>

/*
* Consider the following C code:
*/



typedef struct {
	long a[2];
	long *p;
} strA;

typedef struct {
	long u[2];
	long q;
} strB;

strB process(strA s) {
	strB r;
	r.u[0] = s.a[1];
	r.u[1] = s.a[0];
	r.q = *s.p;
	return r;
}

long eval(long x, long y, long z) {
	strA s;
	s.a[0] = x;
	s.a[1] = y;
	s.p = &z;
	strB r = process(s);
	return r.u[0] + r.u[1] + r.q;
}

/* GCC generates the following assembly for the two functions:
 *
 * 1  process:
 * 2    movq %rdi, %rax		; rax = &(rsp + 64)
 * 3    movq 24(%rsp), %rdx	; rdx = address of stack pointer + 24, which is the pointer pointing to z.
 * 4    movq (%rdx), %rdx       ; dereference the pointer to z and put its value in rdx
 * 5    movq 16(%rsp), %rcx	; rcx = y
 * 6    movq %rcx, (%rdi)	; r.u[0] = rcx, so r.u[0] = y
 * 7    movq 8(%rsp), %rcx	; rcx = x
 * 8    movq %rcx, 8(%rdi)	; r.u[1] = rcx, so r.u[1] = x
 * 9    movq %rdx, 16(%rdi)	; r.q = z
 * 10   ret			; return with rax pointing to the start of strB r
 *
 * 1  eval:
 * 2    subq $104, %rsp		; rsp -= 104
 * 3    movq %rdx, 24(%rsp)	; *(rsp + 24) = z
 * 4    leaq 24(%rsp), %rax	; rax = &(rsp + 24)
 * 5    movq %rdi, (%rsp)	; *rsp = x
 * 6    movq %rsi, 8(%rsp)	; *(rsp + 8) = y
 * 7    movq %rax, 16(%rsp)	; *(rsp + 16) = rax  (= &(rsp + 24))
 * 8    leaq 64(%rsp), %rdi	; rdi = &(rsp + 64)
 * 9    call process
 * 10   movq 72(%rsp), %rax
 * 11   addq 64(%rsp), %rax
 * 12   addq 80(%rsp), %rax
 * 13   addq $104, %rsp
 * 14   ret
 *
 *   A. We can see on line 2 of function eval that it allocates 104 bytes on the stack.
 *   Diagram the stack frame for eval, showing the values that it stores on the stack
 *   prior to calling process.
 *  
 *   
 *   sp+104
 *   sp+96
 *   sp+88
 *   sp+80
 *   sp+72
 *   sp+64   this is where strB r will go
 *   sp+56
 *   sp+48
 *   sp+40
 *   sp+32
 *   sp+24   z
 *   sp+16:  s.p = address of sp + 24
 *   sp+8:   s.a[1] = y
 *   sp:     s.a[0] = x
 *   
 *
 *   B. What value does eval pass in its call to process?
 *
 *   eval passes the memory location where r will go, so process can fill it and the surrounding
 *   stack memory locations with values.
 *
 *
 *   C. How does the code for process access the elements of structure argument s?
 *
 *   By adding constants to the stack pointer and dereferencing those addresses.
 *
 *
 *   D. How does the code for process set the fields of result structure r?
 *
 *   By dereferencing the stack pointer plus different quantities of bytes.
 *
 *
 *   E. Complete your diagram of the stack frame for eval, showing how eval
 *   accesses the elements of structure r following the return from process.
 * 
 *   sp+104
 *   sp+96
 *   sp+88
 *   sp+80   r.q = z
 *   sp+72   r.u[1] = x
 *   sp+64   r.u[0] = y
 *   sp+56
 *   sp+48
 *   sp+40
 *   sp+32
 *   sp+24   z
 *   sp+16:  s.p = sp+24 address
 *   sp+8:   s.a[1] = y
 *   sp:     s.a[0] = x
 *   
 *
 *   F. What general principles can you discern about how structure values
 *   are passed as function arguments and how they are returned as function results?
 *
 *   Structures are sometimes passed by reference in the assembly code, even if the C
 *   source code passes the structure by value.
 *
 */

	
int main() {

	long x = 5, y = 10, z = 15, result;
	result = eval(x, y, z);
	printf("%ld\n", result);
    	return 0;
}
