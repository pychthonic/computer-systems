/*
 *
 * Consider the following union declaration:
 */

union ele {
	struct {
		long *p;
		long y;
	} e1;
	struct {
		long x;
		union ele *next;
	} e2;
};

/* This declaration illustrates that structures can be embedded within unions.
 * The following function (with some expressions omitted) operates on a linked
 * list having these unions as list elements:
 *
 */

void proc (union ele *up) {
	up->_____ = *(_____) - __________;
}

/* A. What are the offsets (in bytes) of the following fields:
 *
 * e1.p: 0
 * e1.y: 8
 * e2.x: 0
 * e2.next: 8
 *
 * B. How many total byes does the structure require?
 *
 * 16 bytes
 *
 * C. The compiler generates the following assembly for proc:
 *
 * proc:
 *   movq 8(%rdi), %rax		; rax = up.next  (address to the first byte of next node)
 *   movq (%rax), %rdx		; rdx = *rax (so rdx = up->next.p)
 *   movq (%rdx), %rdx		; rdx = *up->next.p
 *   subq 8(%rax), %rdx		; rdx -= *up->next.y
 *   movq %rdx, (%rdi)		; up->x = rdx
 *   ret
 *
 * Using this, fill in the missing expressions in the code for proc. Hint: some
 * union references can have ambiguous interpretations. These ambiguities get
 * resolved as you see where the references lead. There is only one answer that
 * does not perform any casting and does not violate any type constraints.
 *
 */


void proc (union ele *up) {
	up->x = *(up->next.p) - *(up->next.y)
}



int main() {
    	return 0;
}
