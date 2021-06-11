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
 * 3    movq 24(%rsp), %rdx	; rdx = z   ???? Shouldn't this be leaq.....?? 
 * 4    movq (%rdx), %rdx	; rdx = *rdx  ???????????????????? this makes no sense to me. The value of
 * 				; z was put in rdx in line 3 of process, not the address of z.
 * 5    movq 16(%rsp), %rcx	; rcx = *(rsp + 16) = &z
 * 6    movq %rcx, (%rdi)	; s.u[0] = rcx, so s.u[0] = &(sp + 16)
 * 7    movq 8(%rsp), %rcx	; rcx = &(sp + 8)
 * 8    movq %rcx, 8(%rdi)	; s.u[1] = rcx, so s.u[1] = &(sp + 8)
 * 9    movq %rdx, 16(%rdi)	; TBC
 * 10   ret
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
 *   F. What general principles can you discern about how structure values
 *   are passed as function arguments and how they are returned as function results?
 *
 *
 */

	
int main() {
    	return 0;
}
