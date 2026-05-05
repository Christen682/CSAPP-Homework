/*simple list implementation*/
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef Node *List;

/*Operation: initialize a list
  Precondition: plist points to a list
  Postcondition: the list is initialized with zero items
*/
void InitializeList(List *plist);

/*Operation: Ensure that a list is empty
  Precondition: plist points to a list
  Postcondition: returns true if the list is empty, otherwise false
*/
bool ListIsEmpty(const List *plist);

/*Operation: Ensure that a list is full
  Precondition: plist points to a list
  Postcondition: returns true if the list is full, otherwise false
*/
bool ListIsFull(const List *plist);

/*Operation: Determine the number of items in a list
  Precondition: plist points to a list
  Postcondition: returns the number of items in the list pointed to by plist
*/
unsigned int ListItemCount(const List *plist);

/*Operation: Add an item to a list
  Precondition: item is an item to be added to the list pointed to by plist
  Postcondition: if possible, item is added to the end of the list and function returns true; otherwise, the list is unchanged and the function returns false
*/
bool AddItem(Item item, List *plist);

/*Operation: Apply a function to each item in a list
  Precondition: plist points to a list and pfun points to a function that takes an Item argument and has no return value
  Postcondition: the function pointed to by pfun is executed once for each item in the list pointed to by plist
*/
void Traverse(const List *plist, void (*pfun)(Item item));

/*Operation: Empty a list
  Precondition: plist points to a list
  Postcondition: the list pointed to by plist is empty
*/
void EmptyTheList(List *plist);

#endif