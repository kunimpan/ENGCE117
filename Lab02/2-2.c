#include <stdio.h>

void GetText( char *text ); //Prototype

int main(){
    char str[20];
    GetText(str);
    printf("%s", str);
    return 0;
}

void GetText( char *text ) { 
    printf("Enter your text : ");
    gets(text);
}