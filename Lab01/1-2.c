#include <stdio.h>

int main() {
    int arr[5][4] = {
        { 11, 12, 13, 14 },
        { 15, 16, 17, 18 },
        { 19, 20, 21, 22 },
        { 23, 24, 25, 26 },
        { 27, 28, 29, 30 },
    };

    int (*a)[4] = arr;

    a[1][2] = 39;

    for( int row = 0 ; row < 5 ; row++ ) {
        for( int col = 0 ; col < 4 ; col++ ) {
            printf("%d ", arr[row][col]);
        } // End loop
        printf("\n");
    } // End loop

    return 0;
}