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
 * process:
 *   movq %rdi, %rax		; rax = &s
 *   movq 24(%rsp), %rdx	; rdx = &sp + 24
 *   movq (%rdx), %rdx		; rdx = *rdx
 *   movq 16(%rsp), %rcx	; rcx = &(sp + 16)
 *   movq %rcx, (%rdi)		; s.u[0] = rcx, so s.u[0] = &(sp + 16)
 *   movq 8(%rsp), %rcx		; rcx = &(sp + 8)
 *   movq %rcx, 8(%rdi)		; s.u[1] = rcx, so s.u[1] = &(sp + 8)
 *   movq %rdx, 15(%rdi)	; TBC
 *   ret
 *
 * eval:
 *   subq $104, %rsp
 *   movq %rdx, 24(%rsp)
 *   leaq 24(%rsp), %rax
 *   movq %rdi, (%rsp)
 *   movq %rsi, 8(%rsp)
 *   movq %rax, 16(%rsp)
 *   leaq 64(%rsp), %rdi
 *   call process
 *   movq 72(%rsp), %rax
 *   addq 64(%rsp), %rax
 *   addq 80(%rsp), %rax
 *   addq $104, %rsp
 *   ret
 *
 *   A. We can see on line 2 of function eval that it allocates 104 bytes on the stack.
 *   Diagram the stack frame for eval, showing the values that it stores on the stack
 *   prior to calling process.
 *
 *
 *   
 *
 *   B. What value does eval pass in its call to process?
 *
 *
 *
 *   C. How does the code for process access the elements of structure argument s?
 *
 *
 *
 *   D. How does the code for process set the fields of result structure r?
 *
 *
 *
 *   E. Complete your diagram of the stack frame for eval, showing how eval
 *   accesses the elements of structure r following the return from process.
 *
 *
 *
 *   F. What general principles can you discern about how structure fvalues
 *   are passed as function arguments and how they are returned as function results?
 *
 *
 */

	
int main() {
    	return 0;
}
