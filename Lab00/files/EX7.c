#include <stdio.h>
#include <string.h>
int main()
{
    char a[30];
    do
    {
        printf("Want to be successful at a young age.\n");
        printf("The problem is just an unanswered question.\n");
        printf("Don't believe everything you see.\n");
        printf("Don't be afraid to make decisions.");
        printf("buy books.");
        printf("Found a good book? : ");
        scanf("%s", &a);
    } while (strcmp(a, "no") == 0);
    printf("get a good book.\n");
}