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

void show_bytes(byte_pointer start, size_t len);

#endif