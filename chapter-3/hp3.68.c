/*
 *
 * Consider the following source code, where A and B are constants defined with #define:
 *
 *
 *
 */

typedef struct {
	int x[A][B]; /* Unknown constants A and B */
	long y;
} str1;

typedef struct {
	char array[B];
	int t;
	short s[A];
	long u;
} str2;

void setVal(str1 *p, str2 *q) {
	long v1 = q->t;
	long v2 = q->u;
	p->y = v1 + v2;
}

/*
* GCC generates the following assembly:
*
* setVal:
*   movslq 8(%rsi), %rax
*   addq 32(%rsi), %rax
*   movq %rax, 184(%rdi)
*   ret
*
*
* What are the values of A and B? (The solution is unique)
*
* This one was easy compared with hp3.67. In setVal, rax is set to
* rsi + 8, so since &q = rsi, &q->t = rsi + 8, and there must be 8 char's
* in str->array, so B must be at most 8.
*
* Then in line 11, it adds 32 to rsi and puts that value into v2. So &q->u
* must be 32 bytes more than &q, and array s[A] must total 20 bytes, since
* 32 - (8 + 4) = 20. A short holds 2 bytes, so A must be at most 10.
*
* There is the possibility of padding -- for example, if str2 q->array[] held
* 7 chars, the address of q->t would still be &q + 8.
*
* Since p->y is found by adding 184 to rdi, p->y must be &p + 184, and 4*A*B = 184
* 
* 4 * 10 * 8 = 320, which is too large.
* 
* 4 * 9 * 8 = 288, which is too large
*
* 4 * 9 * 7 = 252, which is too large.
*
* 4 * 9 * 5 = 180, which is sizeof(x[A][B]) + 4 bytes of padding.
*
* Note that 4 * 8 * 6 wouldn't work, as it's too large, 
* and 4 * 8 * 5 wouldn't work, as it would need 24 bytes of padding, which would
* be too much padding. Since 45 ints would be 45 * 4 = 180 bytes, it would make
* sense for the compiler to round up 4 bytes to make it an even number of ints,
* so:
*
* A = 5
* B = 9
*
*/

int main() {
    	return 0;
}
