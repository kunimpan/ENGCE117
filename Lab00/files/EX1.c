#include <stdio.h>
#include <string.h>

int main()
{
    char equipment[100], temperature[10];
    printf("Insert equipment : ");
    scanf("%s", equipment);
    printf("Turn on the gas, set up the pot, fill with water.\n");
    do
    {
        printf("Is the water boiling? : ");
        scanf("%s", temperature);
    } while (strcmp(temperature, "no") == 0);
    printf("Put the noodles in the pot with seasoning.\n");
    printf("Wait 3 minutes.\n");
    printf("Pour into a cup.\n");
    printf("Ready-to-eat noodles.\n");
}