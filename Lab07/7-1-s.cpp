#include <stdio.h>
#include <string.h>

struct studentNode
{
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode *next;
  struct studentNode *back;
};

class LinkedList
{
protected:
  struct studentNode *start, **now;

public:
  LinkedList();  // กำหนดค่าเริ่มต้นของ start และ now
  // ~LinkedList(); // คืนหน่วยความจำที่จองไว้ในลิงค์ลิสต์ทุกโหนด
  // void InsNode( char n[], int a, char s, float g );
  // void DelNode(); 
  void ShowAll();
  // void ShowBack();
  void AddNode( int a );
  // struct studentNode *start, **now;
}; // end class

int main()
{
  LinkedList listA;
  
  listA.AddNode(10);
  
  listA.AddNode(10);
  listA.AddNode(10);
  
  listA.ShowAll();
 

  // listA.InsNode("one", 1, 'A', 1.1);
  // listA.InsNode("two", 2, 'B', 2.2);
  // listA.InsNode("three", 3, 'C', 3.3);
  return 0;
};

void LinkedList :: AddNode(int a ){
  
  struct studentNode **walk;
  walk = &(this->start);
  
  struct studentNode *temp = NULL;
  
  while( *walk != NULL ){
    
    temp = *walk;
    walk = &(*walk)->next;
    
  } // end while

  *walk = new struct studentNode;
  (*walk)->age = a;

  (*walk)->next = NULL;
  (*walk)->back = temp;

} //end function

void LinkedList :: ShowAll(){
  struct studentNode **walk;
  walk = &(this->start);

  while ( *walk != NULL ){
    printf("%d ", (*walk)->age);
    *walk = (*walk)->next;
  }
  printf("\n");
  
} //end function

LinkedList ::LinkedList()
{
  this->start = NULL;
}

// LinkedList ::~LinkedList()
// {
//   printf("BOOB");
// }
