#ifndef SHOW_BYTES_H
#define SHOW_BYTES_H

#include <stddef.h>


typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

#endif