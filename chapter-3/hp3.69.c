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
 * 	0:  8b 8e 20 01 00 00		mov 0x120(%rsi), %ecx 		; rcx = bp + 288
 *	5:  03 0e			add (%rsi), %ecx		; rcx += bp->first
 *	8:  48 8d 04 bf			lea (%rdi, %rdi, 4), %rax
 *	c:  48 8d 04 c6			lea (%rsi, %rax, 8), %rax	; rax = (40 * n) + bp
 *	10: 48 8b 50 08			mov 0x8(%rax), %rdx		; rdx = *(rax + 8)
 *	14: 48 63 c9			movslq %ecx, %rcx		; rcx = sign-extended ecx
 *	17: 48 89 4c d0 10		mov %rcx, 0x10(%rax, %rdx, 8)	; *(rdx * 8 + rax + 16) = rcx
 *	1c: c3				retq
 *
 * User reverse engineering to find the following:
 * 
 * A. The value of CNT
 *
 * We know from line 0 that &bp->last = &bp + 0x120
 *
 * If we find sizeof(a_struct), we can find out CNT.
 *
 * After line 5, rcx holds n.
 *
 * n is multiplied by 40 added to bp and put in rax, and rax then has 8 added to it. This means
 * that sizeof(a_struct) is 40, and there's 4 bytes of padding after bp->first, which takes up
 * 4 bytes as an int. 
 * 
 * 0x120 in decimal is 288
 *
 * CNT = (288 - 8) / 40 = 3
 *
 * B. A complete declaration of structure a_struct. Assume that hte only fields 
 * in this structure are idx and x, and that both of these contain signed values.
 *
 * So we know from A that sizeof(a_struct) is 40.
 *
 * At line 17, I think rax holds (&bp->a[i] - 8)
 *
 * rdx holds the 8-byte value found at bp->a[i], which seems like it's probably ap->idx
 *
 *
 * &ap->x[ap->idx] = rdx * 8 + rax + 16
 * 
 * 16 is 8 bytes of space taken up by bp->first (4 for int plus padding), plus 8 bytes of
 * space taken up by ap->idx.
 *
 * So a_struct must be the following:
 *
 */

typedef struct {
	long idx;
	long x[4];
} a_struct;



int main() {
    	return 0;
}
