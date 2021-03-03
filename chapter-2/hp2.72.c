#include <stdio.h>
#include <string.h>

#include "chapter2.h"


/* 

The bad code given to fix is this:

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes-sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

A. The variable maxbytes is a signed int, while sizeof(val) returns a size_t,
which is unsigned. So the comparison (maxbytes-sizeof(val) >= 0) will
convert maxbytes to unsigned, which can never be less than 0, so the if clause
will always be true.

B. See below
*/

void safe_copy_int(int val, void *buf, size_t maxbytes) {
    if (maxbytes >= sizeof(val)) {
        printf("\nSUCCESSFUL COPY:\n");
        printf("val: %d, buf: %p, maxbytes: %lu\n", val, buf, maxbytes);
        memcpy(buf, (void*) &val, sizeof(val));
    } else {
        printf("\nNOT ENOUGH BYTES:\n");
        printf("val: %d, buf: %p, maxbytes: %lu\n", val, buf, maxbytes);
    }
}

int main() {

    // Tests:

    int value1 = 10;
    int val;
    void* buf = &value1;
    size_t maxbytes;

    val = 5;
    maxbytes = 4;
    safe_copy_int(val, buf, maxbytes);
    printf("safe_copy_int(%d, %p, %lu);\nprintf(\"%%d\", *(int*) buf); --> %d\n", 
            val, buf, maxbytes, *(int*) buf);

    val = 41;
    maxbytes = 3;
    safe_copy_int(val, buf, maxbytes);
    printf("safe_copy_int(%d, %p, %lu);\nprintf(\"%%d\", *(int*) buf); --> %d\n", 
            val, buf, maxbytes, *(int*) buf);

    maxbytes = 5;
    safe_copy_int(val, buf, maxbytes);
    printf("safe_copy_int(%d, %p, %lu);\nprintf(\"%%d\", *(int*) buf); --> %d\n", 
            val, buf, maxbytes, *(int*) buf);

    printf("\n");

    return 0;
}