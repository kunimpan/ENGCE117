#include <stdio.h>

void increment( int *x ){
    (*x) = 10;
}

int main(){
    int a = 5;
    increment(&a);
    printf("a = %d\n", a);
    return 0;
}