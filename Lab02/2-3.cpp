#include <stdio.h>
#include <string.h>

char *GetText();

int main()
{
    char str[20];
    strcpy( str, GetText() );
    printf("%s", str);
    return 0;
}

char *GetText(){
    char *text = new char[20];
    printf("Enter your text : ");
    gets(text);
    return text;
}