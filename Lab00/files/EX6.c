#include <stdio.h>
#include <string.h>
int main()
{
    char a[30];
    do
    {
        printf("Find the target group.\n");
        printf("Choose the right social media.\n");
        printf("Promotional posts or ads.\n");
        printf("Gain experience");
        printf("Have 1000 customers in the store? : ");
        scanf("%s", &a);
        printf("Keep statistics.\n");
    } while (strcmp(a, "no") == 0);
    printf("1000 customers enter the store.\n");
}