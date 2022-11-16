#include <stdio.h>

int main()
{
    int Max, BigData = 0, Data = 0, Sort = 1;
    for (Max = 0; Max < 100; Max++)
    {
        printf("Enter your number ");
        printf("%d : ", Sort);
        scanf("%d", &Data);
        Sort++;
        if (Data > BigData)
        {
            BigData = Data;
        }
    };
    printf("Largest value : %d", BigData);
}