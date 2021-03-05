#include <stdio.h>
#include <string.h>

#include "chapter2.h"


/* Returns 1 if the computation x-y does not overflow */
int tsub_ok(int x, int y) {
    if (x >= 0 && y < 0 && x - y <= 0) {
        return 0;
    } else if (x < 0 && y > 0 && x - y >= 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    
    // Tests:

    int x, y;

    x = 5;
    y = 10;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = 10;
    y = 5;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = INT_MAX - 5;
    y = -6;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = -6;
    y = INT_MAX - 5;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = -7;
    y = INT_MAX - 5;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = INT_MIN;
    y = INT_MIN;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = INT_MIN;
    y = INT_MAX;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = INT_MAX;
    y = INT_MIN;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = INT_MAX;
    y = INT_MAX;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = 0;
    y = INT_MIN;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    x = 0;
    y = INT_MIN + 1;

    printf("\ntsub_ok(%d, %d) --> %d\n", x, y, tsub_ok(x, y));

    printf("\n");

    return 0;
}