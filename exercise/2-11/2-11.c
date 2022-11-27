#include <stdio.h>

int main()
{
    int n, ans, series = 9;
    printf("User Input : ");
    scanf("%d", &n);
    printf("----\n");
    printf("Series = ");
    for ( int i = 1 ; i <= n ; i++ ) {
        ans += series;
        if ( i <= n-1 ) {
            printf("%d + ", series);
        }
        else {
            printf("%d", series);
        }
        series = series * 10 + 9;
    }
    printf("\nSum = %d", ans);
}