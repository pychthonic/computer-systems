#ifndef CHAPTER2_H
#define CHAPTER2_H

#ifndef STDDEF_H
#define STDDEF_H
#include <stddef.h>
#endif

#ifndef LIMITS_H
#define LIMITS_H
#include <limits.h>
#endif

typedef unsigned char *byte_pointer;

float u2f(unsigned u);
void show_bytes(byte_pointer start, size_t len);
void show_bits(byte_pointer start, size_t len);
void show_var_bits(byte_pointer start, size_t len);
int bang(int x); 

#endif
