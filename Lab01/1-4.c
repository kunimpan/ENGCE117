#include <stdio.h>

int main(){
    int row, col, i, j, *arr;
    printf("Enter your rows : ");
    scanf("%d", &row);
    printf("Enter your cols : ");
    scanf("%d", &col);

    arr[ row * col ];

    for( int i = 0 ; i < row ; i++ ) {
        for( int j = 0 ; j < col ; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf( "%d", &arr[ i * col + j ]);
        }
    }

    return 0;
}