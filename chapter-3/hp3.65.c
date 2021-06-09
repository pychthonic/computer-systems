/*
 *
 * Consider the following source code:
 *
 */

void tranpose(long A[M][M]) {
	long i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < i; j++) {
			long t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
}

/*
 * When compiled with optimization level -O1, GCC generates the following
 * code for the inner loop of the function:
 *
 * .L6:
 * 1  movq (%rdx), %rcx	; rcx = *rdx
 * 2  movq (%rax), %rsi  ; rsi = *rax
 * 3  movq %rsi, (%rdx)  ; *rdx = *rax
 * 4  movq %rcx, (%rax)	; *rax = *rcx
 * 5  addq $8, %rdx	; rdx += 8
 * 6  addq $120, %rax	; rax += 120
 * 7  cmpq $rdi, $rax	; compare rdi to rax
 * 8  jne .L6
 *
 * We can see the GCC has converted the array indexing to pointer code.
 *
 * A. Which register holds the pointer to array element A[i][j]?
 * 
 * Since line 5 adds 8 to rdx, rdx must hold A[i][j]. The reasoning for
 * this is &A[i][j+1] = &A[i][j] + 8
 *
 * B. Which register holds a pointer to array element A[j][i]?
 *
 * Since line 6 adds 120 to rax, rax must hold A[j][i]. The reasoning for
 * this is that &A[j+1][i] = &A[j][i] + 8 * M, and 8 * M = 120
 *
 * C. What is the value of M?
 *
 * From B, we know 120 = 8 * M, so M = 15
 *
 */


int main() {
    	return 0;
}
