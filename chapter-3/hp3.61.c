#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* 
 * In section 3.6.6, we examined the following code as a candidate for the use of conditional data
 * transfer:
 *
 * long cread(long *xp) {
 * 	return (xp ? *xp : 0);
 * 	}
 *
 * We showed a trial implementation using a conditional move instruction but argued that itw as not valid,
 * since it would attempt to read from a null address.
 *
 * Write a C function cread_alt that has the same behavior as cread, except that it can be compiled to
 * use conditional data transfer. When compiled, the generated code should use a conditional move
 * instruction rather than one of the jump instructions.
 *
 */

/* First try was this: */

long cread_alt1(long *xp) {
	if (!xp) {
		return 0;
	} else {
		return *xp;
	}
}

/* However, this function produced the following assembly code:
 *

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Breakpoint 1, 0x000055555555514d in cread_alt1 ()
(gdb) disass
Dump of assembler code for function cread_alt1:
   0x0000555555555149 <+0>:	push   %rbp
   0x000055555555514a <+1>:	mov    %rsp,%rbp
=> 0x000055555555514d <+4>:	mov    %rdi,-0x8(%rbp)
   0x0000555555555151 <+8>:	cmpq   $0x0,-0x8(%rbp)
   0x0000555555555156 <+13>:	jne    0x55555555515f <cread_alt1+22>
   0x0000555555555158 <+15>:	mov    $0x0,%eax
   0x000055555555515d <+20>:	jmp    0x555555555166 <cread_alt1+29>
   0x000055555555515f <+22>:	mov    -0x8(%rbp),%rax
   0x0000555555555163 <+26>:	mov    (%rax),%rax
   0x0000555555555166 <+29>:	pop    %rbp
   0x0000555555555167 <+30>:	ret
End of assembler dump.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


* As you can see, although it successfully avoids dereferencing a null pointer, it doesn't use
* any conditional moves, and instead uses jump instructions. I'm going to have to re-read the
* section in question.
*/

/* Next try: */

long cread_alt2(long *xp) {
	return (!xp ? 0 : *xp);
}


/* This produced the following assembly:
 *

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Breakpoint 1, cread_alt2 (xp=0x7fffffffe7b0) at hp3.61.c:67
(gdb) disass
Dump of assembler code for function cread_alt2:
   0x0000555555555168 <+0>:	push   %rbp
   0x0000555555555169 <+1>:	mov    %rsp,%rbp
   0x000055555555516c <+4>:	mov    %rdi,-0x8(%rbp)
=> 0x0000555555555170 <+8>:	cmpq   $0x0,-0x8(%rbp)
   0x0000555555555175 <+13>:	je     0x555555555180 <cread_alt2+24>
   0x0000555555555177 <+15>:	mov    -0x8(%rbp),%rax
   0x000055555555517b <+19>:	mov    (%rax),%rax
   0x000055555555517e <+22>:	jmp    0x555555555185 <cread_alt2+29>
   0x0000555555555180 <+24>:	mov    $0x0,%eax
   0x0000555555555185 <+29>:	pop    %rbp
   0x0000555555555186 <+30>:	ret
End of assembler dump.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

As you can see, nothing substantial changed. The only difference is it used jne instead of je 
so that the same instructions end up appearing on different lines.
*/

/*
 * Maybe this will do the trick:
 *
*/

long cread_alt3(long* xp) {
	long result = 0;
	if (xp) {
		result = *xp;
	}
	return result;
}


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Breakpoint 1, cread_alt3 (xp=0x7fffffffe7a0) at hp3.61.c:104
(gdb) disass
Dump of assembler code for function cread_alt3:
   0x0000555555555187 <+0>:	push   %rbp
   0x0000555555555188 <+1>:	mov    %rsp,%rbp
   0x000055555555518b <+4>:	mov    %rdi,-0x18(%rbp)
=> 0x000055555555518f <+8>:	movq   $0x0,-0x8(%rbp)
   0x0000555555555197 <+16>:	cmpq   $0x0,-0x18(%rbp)
   0x000055555555519c <+21>:	je     0x5555555551a9 <cread_alt3+34>
   0x000055555555519e <+23>:	mov    -0x18(%rbp),%rax
   0x00005555555551a2 <+27>:	mov    (%rax),%rax
   0x00005555555551a5 <+30>:	mov    %rax,-0x8(%rbp)
   0x00005555555551a9 <+34>:	mov    -0x8(%rbp),%rax
   0x00005555555551ad <+38>:	pop    %rbp
   0x00005555555551ae <+39>:	ret    
End of assembler dump.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*
 * This time, we reduced the jump count to 1.
 * 
 * After reading through 3.6.6 again, it seems cread_alt2 is what the book is going for.
 *
 * My reasoning for this is:
 *
 * On page 214, the function absdiff follows the same structure as cread_alt2, where we have an if/else clause and
 * a variable is assigned a value depending on whether the if clause test is true. And in the book, the compiled
 * code for that function uses cmovge instead of any jumps. I think the compiler and computer I'm on is just
 * compiling differently.
 *
*/


int main() {
	long x = 5;
	long* xp = &x;
	long* xp_null = 0;
	
	long y = cread_alt1(xp);
	long z = cread_alt1(xp_null);
	printf("y = %ld\n", y);
	printf("z = %ld\n", z);	

	long a = cread_alt2(xp);
	long b = cread_alt2(xp_null);
	printf("a = %ld\n", a);
	printf("b = %ld\n", b);
   	
	long c = cread_alt3(xp);
	long d = cread_alt3(xp_null);
	printf("c = %ld\n", y);
	printf("d = %ld\n", z);
   
    	return 0;
}
