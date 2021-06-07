/*
 *
 * For the following assembly:
 * 
 * .L8:
 *   movl $27, %eax      ; return 27
 *   ret
 * .L3:
 *   movq (%rsi), %rax   ; val = *p2;
 *   movq (%rdi), %rdx   ; 
 *   movq %rdx, (%rsi)   ; *p2 = *p1;
 *   ret		 ; return val;
 * .L5:
 *   movq (%rdi), %rax   ; val = *p1;
 *   addq (%rsi), %rax   ; val += *p2;
 *   movq %rax, (%rdi)   ; *p2 = val;
 *   ret		 ; return val;
 * .L6:
 *   movq $59, (%rdi)	 ; *p1 = 59;
 *   movq (%rsi), %rax	 ; return *p2;
 *   ret
 * .L7:
 *   movq (%rsi), %rax   ; val = *p2;
 *   movq %rax, (%rdi)   ; *p1 = val;
 *   movl $27, %eax 	 ; return 27;
 *   ret
 * .L9:
 *   movl $12, %eax	 ; return 12;
 *   ret
 *
 * Fill in the missing parts of the C code:
 */

typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

long switch3(long *p1, long *p2, mode_t action) {
	long result = 0;
	switch(action) {
		case MODE_A:
			result = *p2;
			*p2 = *p1;
			break;
		case MODE_B:
			result = *p1;
			result += *p2;
			*p2 = result;
			break;
		case MODE_C:
			*p1 = 59;
			result = *p2;
			break;
		case MODE_D:
			*p1 = *p2;
			result = 27;
		case MODE_E:
			break;
		default:
			result = 12;
			break;
	}
	return result;
}

int main() {
    	return 0;
}
