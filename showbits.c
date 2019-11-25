#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_chars(byte_pointer start, size_t len) {
    printf("Chars:  ");
    int i;
    for (i=0; i<len; i++) {
        printf("       %c", start[i]);
        if (i < len - 1)
            printf(" |  ");
    }
    printf("\n");
}

void show_bytes(byte_pointer start, size_t len) {
    printf("Bytes:  ");
    int i;
    for (i=0; i<len; i++) {
        printf("    0x%.2x", start[i]);
        if (i < len - 1)
            printf(" |  ");
    }
    printf("\n");
}

void show_bits(byte_pointer start, size_t len) {
    printf("Bits:  ");
    unsigned int bit;
    unsigned char temp_byte;
    for (int i=0; i<len; i++) { 
        for (int j=8; j>0; j--) {
            if (j == 4) {
                printf(" ");
            }
            temp_byte = start[i] >> j - 1;
            bit = temp_byte & 1; 
            printf("%d", bit);
        }
        if ( i < len - 1 )
            printf(" | ");
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float f) {
    show_bytes((byte_pointer) &f, sizeof(float));
}

void show_pointer(void* p) {
    show_bytes((byte_pointer) &p, sizeof(void*));
}

size_t get_string_len(char* char_p) {
    int i = 0;
    while (*char_p != 0) {
        char_p++; 
        i++;
    }
    return i;
}

void inplace_swap(char* x, char* y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void byte_swap(char* x, int len) {
    char* start_ptr;
    start_ptr = x;
    char* end_ptr;
    end_ptr = start_ptr + len - 1;
    while(start_ptr < end_ptr) {
        printf("start_ptr = %c, end_ptr = %c\n", *start_ptr, *end_ptr);
        inplace_swap(start_ptr, end_ptr);
        start_ptr++;
        end_ptr--;
    }
}

int main(int argc, char* argv[]) {
    size_t str_len = get_string_len(argv[1]);
    printf("argv[1] = %s\n", argv[1]);
    show_chars(argv[1], str_len); 
    show_bytes(argv[1], str_len);
    show_bits(argv[1], str_len); 
    printf("argv[1] just before byte_swap: %s\n", argv[1]);
    byte_swap(argv[1], str_len);
    printf("\nSwapping bytes in argv[1]... now argv[1] = %s\n", argv[1]); 
    return 0;
}


