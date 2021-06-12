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
*/

int main() {
    	return 0;
}
