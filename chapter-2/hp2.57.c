#include <stdio.h>

#include "chapter2.h"

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}


int main() {
    
    short s1 = 128;
    long l1 = 2147483647;
    double d1 = 55.15;

    show_short(s1);
    show_long(l1);
    show_double(d1);

    return 0;
}