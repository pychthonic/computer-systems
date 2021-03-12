#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "chapter2.h"


/* 
Instead of assuming f2u, I wrote a function for it.
*/

unsigned f2u(float f) {
    unsigned return_val;
    unsigned char* fptr = (unsigned char*) &f;
    unsigned char* uptr = (unsigned char*) &return_val;

    for (int i = 0; i < sizeof(unsigned); ++i) {
        *(uptr + i) = *fptr;
        fptr++;
    }
    return return_val;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    // Get rid of sign bit, since we don't need it anymore:

    ux = ux & 0x7FFFFFFF;
    uy = uy & 0x7FFFFFFF;

    return (((!sx && !sy) && (ux <= uy)) || ((sx && sy) && uy <= ux) || (sx && !sy) || (!ux && !uy));
}


int main() {
    
    // Tests:

    // Seed the random # generator:
    srand( time(NULL) );

    // Testing f2u first:

    float f0 = 562.423;
    printf("\nf0 bits:\n");
    show_bits((byte_pointer) &f0, sizeof(f0));
    printf("\n");

    unsigned u0 = f2u(f0);
    printf("u0 bits:\n");
    show_bits((byte_pointer) &u0, sizeof(u0));

    /* Casually test float_le with 20 million randomly chosen numbers */

    float f1, f2;
    for (int i = 0; i < 20000000; ++i) {
        f1 = (float) (rand() + rand())/(float)(RAND_MAX/FLT_MAX);
        f2 = (float) (rand() + rand())/(float)(RAND_MAX/FLT_MAX);
        if ((float_le(f1, f2) && (f2 < f1))) {
            printf("Error for:\nf1: %f\nf2: %f\n\n", f1, f2);
        }
    }


    // Create positive and negative infinity and positive and negative zero:

    float float_pos_inf;
    int i1 = 0x7F800000;
    unsigned char* fptr = (unsigned char*) &float_pos_inf;
    unsigned char* iptr = (unsigned char*) &i1;
    for (int i = 0; i < 4; ++i) {
        *(fptr) = *(iptr + i);
        fptr++;
    }

    // printf("\nfloat_pos_inf: %f\n", float_pos_inf);
    // show_bits((byte_pointer) &float_pos_inf, sizeof(float_pos_inf));



    float float_neg_inf;
    i1 = 0xFF800000;
    fptr = (unsigned char*) &float_neg_inf;
    iptr = (unsigned char*) &i1;
    for (int i = 0; i < 4; ++i) {
        *(fptr) = *(iptr + i);
        fptr++;
    }

    // printf("\nfloat_neg_inf: %f\n", float_neg_inf);
    // show_bits((byte_pointer) &float_neg_inf, sizeof(float_neg_inf));



    float float_neg_zero;
    i1 = 0x80000000;
    fptr = (unsigned char*) &float_neg_zero;
    iptr = (unsigned char*) &i1;
    for (int i = 0; i < 4; ++i) {
        *(fptr) = *(iptr + i);
        fptr++;
    }

    // printf("\nfloat_neg_zero: %f\n", float_neg_zero);
    // show_bits((byte_pointer) &float_neg_zero, sizeof(float_neg_zero));


    float float_pos_zero = 0.0;

    // printf("\nfloat_pos_zero: %f\n", float_pos_zero);
    // show_bits((byte_pointer) &float_pos_zero, sizeof(float_pos_zero));

    if (!float_le(float_neg_zero, float_pos_zero)) {
        printf("\nError for:\nfloat_le(%f, %f):\n", float_neg_zero, float_pos_zero);
    }

    if (!float_le(float_pos_zero, float_neg_zero)) {
        printf("\nError for:\nfloat_le(%f, %f):\n", float_pos_zero, float_neg_zero);
    }

    if (!float_le(float_neg_inf, float_pos_inf)) {
        printf("\nError for:\nfloat_le(%f, %f):\n", float_neg_inf, float_pos_inf);
    }

    if (float_le(float_pos_inf, float_neg_inf)) {
        printf("\nError for:\nfloat_le(%f, %f):\n", float_pos_inf, float_neg_inf);
    }

    

    float f3 = -3.0, f4 = 3.0;

    if (!float_le(f3, f4)) {
        printf("\nError for:\nfloat_le(%f, %f):\n", f3, f4);
    }

    if (float_le(f4, f3)) {
        printf("\nError for:\nfloat_le(%f, %f):\n", f4, f3);
    }

    printf("\n");

    return 0;
}