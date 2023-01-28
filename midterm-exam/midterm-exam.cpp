// โอภาสพันธ์ กลิ่นชิ่นจิต รหัส 65543206039-1 SEC 2

#include <stdio.h>
#include <string.h>

struct carNode {
    char brand[20];
    int price;
    struct carNode *next;
};

struct carNode *AddCarNode( struct carNode **walk, char newBrand[], int newPrice );//prototype
void ShowAll( struct carNode *walk );// prototype
void UpdateCarNode( struct carNode **walk, char choose[], char newBrand[], int newPrice );// prototype
void ShowBack( struct carNode **walk );//prototype
void SwapNode( struct carNode **walk, char brand1[], char brand2[] ); // prototype

int main(){
    struct carNode *start;
    start = NULL;
    AddCarNode( &start , "Honda", 350000);
    AddCarNode( &start , "Toyota", 430500);
    AddCarNode( &start , "Ford", 600100);
    AddCarNode( &start , "Mazda", 365000);
    ShowAll( start );
    UpdateCarNode( &start , "Ford", "GTR", 15000000);
    ShowAll( start );
    ShowBack ( &start );
    SwapNode ( &start, "Toyota", "Mazda");
    ShowAll( start );
    return 0;
}

struct carNode *AddCarNode( struct carNode **walk, char newBrand[], int newPrice){

    while ( *walk != NULL ){
        walk = &(*walk)->next;
    } // end while

    *walk = new struct carNode;
    strcpy((*walk)->brand, newBrand);
    (*walk)->price = newPrice;
    (*walk)->next = NULL;
    return *walk;

} // end function

void ShowAll( struct carNode *walk ){
    while (walk != NULL)
    {
        printf("%s ", walk->brand);
        printf("%d | ", walk->price);
        walk = walk->next;
    } // end while
    printf("\n");
    
} // end function

void UpdateCarNode ( struct carNode **walk, char choose[], char newBrand[], int newPrice ){

    while ( strcmp((*walk)->brand, choose) != 0 ){
        walk = &(*walk)->next;
    } // end while

    if( (*walk) == NULL ){
        printf("This node does not exist");
        return;
    } //end if

    strcpy((*walk)->brand, newBrand);
    (*walk)->price = newPrice;

} // end function

void ShowBack ( struct carNode **walk ){

    struct carNode *preNode = NULL;
    struct carNode *currentNode = *walk;
    struct carNode *nextNode = NULL;

    while ( currentNode != NULL ){
        nextNode = currentNode->next;
        currentNode->next = preNode;
        preNode = currentNode;
        currentNode = nextNode;
    } // end while

    *walk = preNode;

    while ((*walk) != NULL) {
        printf("%s ", (*walk)->brand);
        printf("%d | ", (*walk)->price);
        (*walk) = (*walk)->next;
    } // end while

} // end function

void SwapNode( struct carNode **walk, char brand1[], char brand2[] ){
   
    if (strcmp(brand1, brand2) == 0){
        printf("Same node \n");
        return;
    } //end if
         
    struct carNode *prevBrand1 = NULL, *currBrand1 = *walk;
    while ( strcmp(currBrand1->brand, brand1) != 0 ) {
        prevBrand1 = currBrand1;
        currBrand1 = currBrand1->next;

        if( currBrand1 == NULL ){
            return;
        } //end if
    }
    

    struct carNode *prevBrand2 = NULL, *currBrand2 = *walk;
    while ( strcmp(currBrand2->brand, brand2) != 0) {
        prevBrand2 = currBrand2;
        currBrand2 = currBrand2->next;

        if( currBrand2 == NULL ){
            return;
        } //end if
    }

    if (prevBrand1 != NULL){
        prevBrand1->next = currBrand2;
    }else{
        *walk = currBrand2;
    } //end if
        
 
    if (prevBrand2 != NULL){
        prevBrand2->next = currBrand1;
    }else{
        *walk = currBrand1;
    } //end if

    struct carNode *temp = currBrand2->next;
    currBrand2->next = currBrand1->next;
    currBrand1->next = temp;

} // end function

