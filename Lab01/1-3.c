#include <stdio.h>

int multiply( int a, int b ); //prototype

int operation( int a, int b, int (*function) (int, int) ); //prototype

int main() {
    int a, b, sum;

    printf("Enter yor first number : ");
    scanf("%d", &a);

    printf("Enter yor second number : ");
    scanf("%d", &b);

    sum = operation(a, b, multiply);

    printf("sum = %d", sum);
    return 0;
}

int multiply( int a, int b ) {
    return a * b;
}

int operation( int a, int b, int (*function) (int, int) ) {
    return (*function) (a, b);
}