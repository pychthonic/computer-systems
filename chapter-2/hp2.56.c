#include <stdio.h>

#include "chapter2.h"

int main() {
    
    int num1 = 128;
    float f1 = 1.55;
    double d1 = 55.15;

    show_bytes((byte_pointer) &num1, sizeof(num1));
    show_bytes((byte_pointer) &f1, sizeof(f1));
    show_bytes((byte_pointer) &d1, sizeof(d1));

    return 0;
}