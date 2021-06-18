/*
 *
 * Write a function in assembly code that matches the behavior of the function find_range in
 * Figure 3.51. Your code should contain only one floating-point comparison instruction, and
 * then it should use conditional branches to generate the correct result. Test your code on
 * all 2^32 possible argument values. Web Aside ASM:EASM on page 178 describes how to
 * incorporate functions written in assembly code into C programs.
 *
 */

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../chapter-2/chapter2.h"

typedef enum {NEG, ZERO, POS, OTHER} range_t;

extern range_t find_range_book(float x);
extern range_t my_find_range(float x);



int main() {
	unsigned u = 0, count;
	float f;
	range_t r_book, my_r;
	
        f = -5.0;

	r_book = find_range_book(f);
	my_r = my_find_range(f);
	printf("f: %f, r_book: %d, my_r: %d\n", f, r_book, my_r);
	
	f = 5.0;

	r_book = find_range_book(f);
	my_r = my_find_range(f);
	printf("f: %f, r_book: %d, my_r: %d\n", f, r_book, my_r);
	
	f = 0;

	r_book = find_range_book(f);
	my_r = my_find_range(f);
	printf("f: %f, r_book: %d, my_r: %d\n", f, r_book, my_r);
	
	f = 0.0 / 0.0;

	r_book = find_range_book(f);
	my_r = my_find_range(f);
	printf("f: %f, r_book: %d, my_r: %d\n", f, r_book, my_r);
	

	for (count=0; count != UINT_MAX; ++count) {
	        f = u2f(count);	
		r_book = find_range_book(f);
		my_r = my_find_range(f);
		assert (r_book == my_r);
		if (my_r != r_book)
			printf("r_book: %d, my_r: %d\n", r_book, my_r);
	}
	count = UINT_MAX;
	f = u2f(count);	
	r_book = find_range_book(f);
	my_r = my_find_range(f);
	assert (r_book == my_r);
    	
	return 0;
}
