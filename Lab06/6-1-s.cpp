#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NULL 0

struct studentNode {
    int age ;
    struct studentNode *next ;
    struct studentNode *back ;
} ;

struct studentNode *AddNode( struct studentNode **walk, int a ); // prototype
void InsNode( struct studentNode *walk, int a ); // prototype
void ShowAll( struct studentNode *walk ) ;// prototype
void GoBack( struct studentNode **walk ) ;// prototype
void DelNode( struct studentNode *walk );// prototype

int main() {
    struct studentNode *start, *now ;
    start = NULL ;
    now = AddNode( &start, 1 ) ; ShowAll( start ) ;
    now = AddNode( &start, 2 ) ; ShowAll( start ) ;
    InsNode( now, 3 ) ; ShowAll( start ) ;
    InsNode( now, 4 ) ; ShowAll( start ) ;
    GoBack( &now ) ;
    printf("------------------------\n");
    DelNode( now ) ; ShowAll( start ) ;
    DelNode( now ) ; ShowAll( start ) ;
    DelNode( now ) ; ShowAll( start ) ;
    return 0 ;
}//end function

struct studentNode *AddNode( struct studentNode **walk, int a ){
    struct studentNode *temp = NULL;

    while ( *walk != NULL )
    {
        temp = *walk;
        walk = &(*walk)->next;
    }// end while
    
    *walk = new struct studentNode;
    (*walk)->age = a;
    (*walk)->next = NULL;
    (*walk)->back = temp;
    return *walk;
}

void InsNode( struct studentNode *walk, int a ){
    if( walk->back != NULL ){
        walk->back->next = new struct studentNode;

        walk->back->next->age = a;

        walk->back->next->next = walk;
        walk->back->next->back = walk->back;
        walk->back = walk->back->next;
    }
}

void GoBack( struct studentNode **walk ){
    (*walk) = (*walk)->back;
}

// void DelNode( struct studentNode *walk ){
//     printf("node now input : %s | ", walk->name);
//     printf("node next : %s | ", walk->back->name);
//     struct studentNode *temp;
//     walk->back->next = walk->next;

//     if( walk->next != NULL ){
//         walk->next->back = walk->back;
//         temp = walk->next;
//         // printf(" test ");
//     }else{
//         temp = walk->back;
//         printf(" test 2 ");
//     }
//     delete walk;
//     walk = temp;
//     walk->back->next = walk;
// }

void DelNode( struct studentNode *walk ){
    // printf("node now input : %d | ", walk->age);
    // printf("node back : %d | ", walk->back->age);
    // printf("node next : %d | ", walk->back->age);
    struct studentNode *temp;
    walk->back->next = walk->next;

    if( walk->next != NULL ){
        walk->next->back = walk->back;
        temp = walk->next;
        // printf(" test ");
    }else{
        temp = walk->back;
        printf(" test 2 ");
    }
    delete walk;
    walk = temp;
    // printf("delete ? : %d | ", walk->age);
    
    // walk->back->next = walk;
}

void ShowAll( struct studentNode *walk ) {
    while( walk != NULL ) {
    printf( "%d ", walk->age ) ;
    walk = walk->next ;
    }//end while
    printf( " \n" ) ;
}//end function