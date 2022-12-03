#include <stdio.h>

void GetArr2D( int **arr, int *row, int *col ); // Prototype

int main(){
    int row, col, *arr;
    GetArr2D( &arr, &row, &col);
    return 0;
}

void GetArr2D( int **arr, int *row, int *col ) {
    printf("Enter your rows : ");
    scanf("%d", row);

    printf("Enter your cols : ");
    scanf("%d", col);

    *arr[ *row * *col ];

    for( int i = 0 ; i < *row ; i++ ) {
        for( int j = 0 ; j < *col ; j++ ) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &(*arr)[ i * *col + j]);
        } // End loop
    } // End loop
}