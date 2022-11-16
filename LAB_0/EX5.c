#include <stdio.h>
#include <string.h>
int main()
{
    char a[30];
    do
    {
        printf("Raise funds.\n");
        printf("Find out about selling online.\n");
        printf("Do it\n");
        printf("Gain experience");
        printf("Is it successful? : ");
        scanf("%s", &a);
    } while (strcmp(a, "no") == 0);
    printf("million\n");
}