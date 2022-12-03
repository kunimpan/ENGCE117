#include <stdio.h>

int main() {
    int *n, sum = 60;
    n = &sum;
    printf("pointer n = %d\n", *n);

    sum = 70;
    printf("pointer n = %d\n", *n);

    *n= 80;
    printf("pointer n = %d\n", *n);
    printf("sum = %d\n", sum);
    return 0;
}