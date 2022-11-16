#include <stdio.h>
#include <string.h>
int main()
{
    char a[30];
    printf("Shower.\n");
    printf("Get dressed.\n");
    printf("walk to the nearby market.\n");
    printf("Closing market? : ");
    scanf("%s", &a);
    if (strcmp(a, "yes") == 0)
    {
        printf("go to another market.\n");
        printf("shopping.\n");
    }
    else
    {
        printf("shopping.\n");
    }
    return 0;
}