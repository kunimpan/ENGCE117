
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void InsNode( struct studentNode **walk, char n[], int a, char s, float g ); //prototype
void GoNext( struct studentNode ***walk ) ; //prototype
void DelNode( struct studentNode **preNode ); //prototype
void ShowAll( struct studentNode **walk ) ; //prototype

int main() {
    struct studentNode *start, **now ;
    start = NULL ; now = &start ;
    InsNode( now, "one", 6, 'M', 3.11 ) ; ShowAll( &start ) ;
    InsNode( now, "two", 8, 'F', 3.22 ) ; ShowAll( &start ) ;
    // GoNext( &now ) ;
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( &start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( &start ) ;
    // GoNext( &now ) ;
    DelNode( now ) ; ShowAll( &start ) ;
    return 0 ;
}//end function

void ShowAll( struct studentNode **walk ) {
    while( *walk != NULL ) {
    printf( "%s ", (*walk)->name ) ;
    walk = &(*walk)->next ;
    }//end while
    printf( " " ) ;
}//end function

void InsNode( struct studentNode **walk, char n[], int a, char s, float g ){
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if(*walk == NULL) {
        *walk = newNode;
    } else {
        struct studentNode *temp = *walk;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
} // end function

void DelNode( struct studentNode **nowNode ){
    struct studentNode *delNode = (*nowNode)->next;
    (*nowNode)->next = delNode->next;
} // end function

void GoNext( struct studentNode ***walk ) {
  **walk = (*(*walk))->next;
} //end function

