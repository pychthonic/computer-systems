#include <stdio.h>

int is_equals(int x, int y) {
    return !(x^y);
}

int main () {
    int a, b;
    printf("Enter num a: ");
    scanf("%d", &a);
    printf("Enter num b: ");
    scanf("%d", &b);
    if (is_equals(a, b))
        printf("%d and %d are equal.\n", a, b);
    else
        printf("%d and %d are not equal.\n", a, b);
}
