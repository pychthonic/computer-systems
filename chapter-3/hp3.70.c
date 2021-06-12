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

/* What are the offsets (in bytes) of the following fields:
 *
 * e1.p:
 * e1.y:
 * e2.x:
 * e2.next:
 *
 * B. How many total byes does the structure require?
 *
 *
 *
 * C. The compiler generates the following assembly for proc:
 *
 * proc:
 *   movq *(%rdi), %rax
 *   movq (%rax), %rdx
 *   movq (%rdx), %rdx
 *   subq 8(%rax), %rdx
 *   movq %rdx, (%rdi)
 *   ret
 *
 * Using this, fill in the missing expressions in the code for proc. Hint: some
 * union references can have ambiguous interpretations. These ambiguities get
 * resolved as you see where the references lead. There is only one answer that
 * does not perform any casting and does not violate any type constraints.
 *
 */

int main() {
    	return 0;
}
