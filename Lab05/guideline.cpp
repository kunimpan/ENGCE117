#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g ); // prototype
void InsNode( struct studentNode *walk, char n[], int a, char s, float g ); // prototype
void DelNode( struct studentNode *walk );// prototype
void ShowAll( struct studentNode *walk );// prototype
void ReverseNodes(struct studentNode **head); // prototype
void SwapNode(struct studentNode *walk); // prototype
void UpdateNode(struct studentNode *walk, char n[], int a, char s, float g); // prototype

int main(){
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11); ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33); ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); ShowAll(start);
    UpdateNode(now, "ten", 100, 'T', 10.10); ShowAll(start);
    SwapNode(now); ShowAll(start);
    DelNode(now); ShowAll(start);
    ReverseNodes(&start); ShowAll(start);
    return 0;
} // end function

void ShowAll( struct studentNode *walk )
{
    while (walk != NULL)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    } // end while
    printf("\n");
    
} // end function

void ReverseNodes(struct studentNode **head) {
    struct studentNode *prev = NULL;
    struct studentNode *current = *head;
    struct studentNode *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    while ((*head) != NULL) {
        printf("%s ", (*head)->name);
        (*head) = (*head)->next;
    }
    printf("\n");
}


struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g ){
    while( *walk != NULL ){
        walk = &(*walk)->next;
    }

    *walk = new struct studentNode;
    strcpy((*walk)->name, n);
    (*walk)->age = a;
    (*walk)->sex = s;
    (*walk)->gpa = g;
    (*walk)->next = NULL;
    return *walk;
} // end function

void InsNode( struct studentNode *walk, char n[], int a, char s, float g ){
    struct studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = walk->next;
    walk->next = newNode;
} // end function

void DelNode(struct studentNode *walk){
    struct studentNode *delNode = walk->next;
    walk->next = delNode->next;
    delete delNode;
}

void SwapNode(struct studentNode *walk){
    struct studentNode *temp = NULL;
    temp = walk;
    char nameTemp[20];
    int ageTemp;
    char sexTemp;
    float gpaTemp;


    strcpy(nameTemp, temp->name);
    ageTemp = temp->age;
    sexTemp = temp->sex;
    gpaTemp = temp->gpa;

    // swap position 2 to 4
    strcpy(walk->name, walk->next->next->name);
    walk->age = walk->next->next->age;
    walk->sex = walk->next->next->sex;
    walk->gpa = walk->next->next->gpa;

    // swap position 4 to 2
    strcpy(walk->next->next->name, nameTemp);
    walk->next->next->age = ageTemp;
    walk->next->next->sex = sexTemp;
    walk->next->next->gpa = gpaTemp;
    
}

// update positon 3
void UpdateNode(struct studentNode *walk, char n[], int a, char s, float g){
    walk = walk->next;
    strcpy(walk->name, n);
    walk->age = a;
    walk->sex = s;
    walk->gpa = g;
}

