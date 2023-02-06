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
  // struct studentNode *start, **now;

public:
  LinkedList(); // กำหนดค่าเริ่มต้นของ start และ now
  // ~LinkedList(); // คืนหน่วยความจำที่จองไว้ในลิงค์ลิสต์ทุกโหนด
  void InsNode(char n[], int a, char s, float g);
  // void DelNode();
  void ShowAll();
  // void ShowBack();
  void AddNode(char n[], int a, char s, float g);
  struct studentNode *start, **now;
}; // end class

int main()
{
  LinkedList listA;
  listA.AddNode("onee", 6, 'M', 3.11);
  // listA.AddNode("two", 6, 'M', 3.11);
  // listA.AddNode("three", 6, 'M', 3.11);
  // printf("| %s |", listA.start->next->name);
  // listA.InsNode("six", 5, 'A', 1.1);
  // listA.AddNode("four", 6, 'M', 3.11);

  // listA.InsNode("one", 1, 'A', 1.1);
  listA.InsNode("two", 2, 'B', 2.2);
  // listA.InsNode("three", 3, 'C', 3.3);
  listA.ShowAll();

  // listA.InsNode("two", 2, 'B', 2.2);
  // listA.InsNode("three", 3, 'C', 3.3);
  return 0;
};

void LinkedList ::AddNode(char n[], int a, char s, float g)
{
  struct studentNode **walk;
  walk = &(this->start);

  struct studentNode *temp = NULL;

  while (*walk != NULL)
  {
    temp = *walk;
    walk = &(*walk)->next;
  } // end while

  *walk = new struct studentNode;
  strcpy((*walk)->name, n);
  (*walk)->age = a;
  (*walk)->sex = s;
  (*walk)->gpa = g;

  (*walk)->next = NULL;
  (*walk)->back = temp;

} // end function

void LinkedList ::InsNode(char n[], int a, char s, float g)
{
  struct studentNode **walk;
  walk = &(this->start);

  if ((*walk)->back != NULL)
  {
    (*walk)->back->next = new struct studentNode;

    strcpy((*walk)->back->next->name, n);
    (*walk)->back->next->age = a;
    (*walk)->back->next->sex = s;
    (*walk)->back->next->gpa = g;

    (*walk)->back->next->next = (*walk);
    (*walk)->back->next->back = (*walk)->back;
    (*walk)->back = (*walk)->back->next;
  }
  else
  {
    struct studentNode *temp = NULL;
    *walk = new struct studentNode;
    strcpy((*walk)->name, n);
    (*walk)->age = a;
    (*walk)->sex = s;
    (*walk)->gpa = g;
    (*walk)->next = NULL;
    (*walk)->back = temp;
  }
} // end function

void LinkedList ::ShowAll()
{
  struct studentNode **walk;
  walk = &(this->start);

  while (*walk != NULL)
  {
    printf("%s ", (*walk)->name);
    *walk = (*walk)->next;
  }
  printf("\n");

} // end function

LinkedList ::LinkedList()
{
  this->start = NULL;
}

// LinkedList ::~LinkedList()
// {
//   printf("BOOB");
// }
