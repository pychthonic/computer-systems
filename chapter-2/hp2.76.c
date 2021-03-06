#include <stdio.h>
#include <stdlib.h>

#include "chapter2.h"



/* Used by my_calloc to check for overflow */
int multiplication_overflow(size_t x, size_t y) {
    if (!x || !y) {
        return 0;
    }

    size_t product = x * y;

    if (product / x == y) {
        return 0;
    } else {
        return 1;
    }

}

/* Implementing calloc function, using built-in malloc. */
void* my_calloc(size_t nmemb, size_t size) {
    if (!nmemb || !size)
        return NULL;
    if (!multiplication_overflow(nmemb, size)) {
        size_t byte_count = nmemb * size;
        unsigned char* new_ptr = (unsigned char*) malloc(byte_count);
        for (int i=0; i<byte_count; ++i) {
            new_ptr[i] = 0;
        }
        return (void*) new_ptr;
    } else {
        return NULL;
    }
}


int main() {
    
    // Tests:

    printf("\n");

    size_t item_size = 4, item_count = 10;

    void* new_ptr = my_calloc(item_count, item_size);

    printf("item size: %lu, item_count: %lu\n", item_size, item_count);
    if (new_ptr) {
        printf("my_calloc call successfull.\nnew_ptr addy: %p\n", new_ptr);
    } else {
        printf("my_calloc returned NULL.\n");
    }


    item_size = -2, item_count = 10;

    new_ptr = my_calloc(item_count, item_size);

    printf("\nitem size: %lu, item_count: %lu\n", item_size, item_count);
    if (new_ptr) {
        printf("my_calloc call successfull.\nnew_ptr addy: %p\n", new_ptr);
    } else {
        printf("my_calloc returned NULL.\n");
    }
    
    item_size = 0, item_count = 10;

    new_ptr = my_calloc(item_count, item_size);

    printf("\nitem size: %lu, item_count: %lu\n", item_size, item_count);
    if (new_ptr) {
        printf("my_calloc call successfull.\nnew_ptr addy: %p\n", new_ptr);
    } else {
        printf("my_calloc returned NULL.\n");
    }


    printf("\n");

    return 0;
}