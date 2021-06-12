/*
 *
 * Consider the following source code:
 *
 */

typedef struct {
	int first;
	a_struct a[CNT];
	int last;
} b_struct;

void test(long i, b_struct *bp) {
	int n = bp->first + bp->last;
	a_struct *ap = &bp->a[i];
	ap->x[ap->idx] = n;
}

/* 
 * The declarations of the compile-time constant CNT and the structure a_struct
 * are in a file for which you do not have the necessary access privilege.
 * Fortunately, you have a copy of the .o version of the code, which you are
 * able to disassemble with objdump, yielding the following disassembly:
 *
 * <test>:
 * 	0:  8b 8e 20 01 00 00		mov 0x120(%rsi), %ecx
 *	5:  03 0e			add (%rsi), %ecx
 *	8:  48 8d 04 bf			lea (%rdi, %rdi, 4), %rax
 *	c:  48 8d 04 c6			lea (%rsi, %rax, 8), %rax
 *	10: 48 8b 50 08			mov 0x8(%rax), %rdx
 *	14: 48 63 c9			movslq %ecx, %rcx
 *	17: 48 89 4c d0 10		mov %rcx, 0x10(%rax, %rdx, 8)
 *	1c: c3				retq
 *
 * User reverse engineering to find the following:
 * 
 * A. The value of CNT
 *
 *
 *
 * B. A complete declaration of structure a_struct. Assume that hte only fields 
 * in this structure are idx and x, and that both of these contain signed values.

int main() {
    	return 0;
}
