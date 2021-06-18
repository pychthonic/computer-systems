/*
 * ISO C99 includes extensions to support complex numbers. Any floating-point
 * type can be modified with the keyword complex. Here are some sample functions
 * that work with complex data and that call some of the associated library
 * functions:
 *
 */

#include <complex.h>

double c_imag(double complex x) {
	return cimag(x);
}

double c_real(double complex x) {
	return creal(x);
}

double complex c_sub(double complex x, double complex y) {
	return x - y;
}

/* When compiled, GCC generates the following assembly:
 *
 * 1  c_imag:
 * 2    movapd %xmm1, %xmm0               ; move aligned packed double from xmm1 to xmm0
 * 3    ret
 *
 * 1  c_real:
 * 2    rep; ret
 *
 * 1  c_sub:
 * 2    subsd %xmm2, %xmm0
 * 3    subsd %xmm3, %xmm1
 * 4    ret
 *
 *
 * Based on these examples,
 *
 * A. How are complex arguments passed to a function?
 *
 * Double complex arguments are passed to a function in two of the floating-point
 * registers for each argument, in xmm0 and xmm1 for the first argument, in xmm2
 * and xmm3 for the second argument.
 *
 * The imaginary number is in the 2nd of each pair, and the real number is in the
 * first of each pair. So for example in c_imag, xmm1 holds the imaginary number,
 * while xmm0 holds the real number.
 *
 *
 * B. How are complex values returned from a function?
 *
 * The real number is returned in xmm0. The imaginary number is returned in xmm1.
 *
 */


int main() {
    	return 0;
}
