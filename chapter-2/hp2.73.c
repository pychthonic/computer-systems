#include <stdio.h>
#include <string.h>

#include "chapter2.h"




/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
    if ((x > 0) && (y > 0) && ((int) (x + y) <= 0)) {
        // The numbers overflowed into negative.
        printf("\nx = %d\ny = %d\nx + y = %d\nReturning INT_MAX", x, y, x + y);
        return INT_MAX;
    } else if ((x < 0) && (y < 0) && (x + y >= 0)) {
        // The numbers overflowed into positive.
        printf("\nx = %d\ny = %d\nx + y = %d\nReturning INT_MIN", x, y, x + y);
        return INT_MIN;
    } else {
        printf("\nx = %d\ny = %d\nx + y = %d\nReturning x + y", x, y, x + y);
        return x + y;
    }
}


int main() {
    
    // Tests:

    int x, y;

    x = 5;
    y = 10;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    x = INT_MAX - 5;
    y = 5;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    x = INT_MAX - 5;
    y = 10;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    x = 550;
    y = -10;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    x = 550;
    y = -6540;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    x = INT_MIN;
    y = INT_MIN;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));
    
    x = INT_MIN + 1;
    y = INT_MIN;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    x = INT_MAX;
    y = INT_MAX;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    x = INT_MIN;
    y = INT_MAX;

    printf("\nsaturating_add(%d, %d) --> %d\n", x, y, saturating_add(x, y));

    printf("\n");

    return 0;
}