/*list.c functions that support the list operations*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*static function defination*/
/*copy an item to a node*/
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
}

/*Initial function*/
/*Allow the list to be Null*/
void InitializeList(List *plist)
{
    *plist = NULL;
}

/*If list is NULL,return true*/
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}

/*If list is full,return true*/
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;

    free(pt);
    return full;
}
/*return the number of nodes in the list*/
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node *pnode = *plist;

    while (pnode != NULL)
    {
        count++;
        pnode = pnode->next;
    }
    return count;
}

/*Create a node that stores items and add it to the tail of the list*/
bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (!scan)
        *plist = pnew;
    else
    {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
    return true;
}

/*Traversing each node and conduct the function pointed by pfun*/
void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *ps = *plist;

    while (ps != NULL)
    {
        (*pfun)(ps->item);
        ps = ps->next;
    }
}

/*Empty the list*/
void EmptyTheList(List *plist)
{
    Node *temp = *plist;

    while (*plist != NULL)
    {
        temp = (*plist)->next;
        free(*plist);
        *plist = temp;
    }
}
