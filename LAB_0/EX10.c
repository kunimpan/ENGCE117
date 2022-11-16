#include <stdio.h>

int main()
{
    int a, b = 0, c = 0;
    for (a = 0; a < 5; a++)
    {
        printf("Enter an integer:");
        scanf("%d", &c);
        printf("Enter an integer: %d", c);
        if (c > b)
        {
            b = c;
        }
    };
    printf("sum %d", b);
    return 0;
}