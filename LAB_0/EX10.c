#include <stdio.h>

int main()
{
    int Max, BigData = 0, Data = 0;
    for (Max = 0; Max < 100; Max++)
    {
        printf("Enter your number:");
        scanf("%d", &Data);
        if (Data > BigData)
        {
            BigData = Data;
        }
    };
    printf("Largest value : %d", BigData);
    return 0;
}