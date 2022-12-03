#include <stdio.h>

int *GetArr2D(int *row, int *col); // Protrotype

int main() {
    int row, col, *arr;
    arr = GetArr2D( &row, &col);
    delete [] arr;
    return 0;
}

int *GetArr2D(int *row, int *col) {
    int *arr;
    printf("Enter your rows : ");
    scanf("%d", row);

    printf("Enter your cols : ");
    scanf("%d", col);

    arr = new int[ *row * *col ];

    for( int i = 0 ; i < *row ; i++ ) {
        for( int j = 0 ; j < *col ; j++ ) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[ i * *col + j]);
        } // End j loop
    } // End i loop
    
    return arr;
}
