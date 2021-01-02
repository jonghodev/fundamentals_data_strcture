#ifndef CLinkedList_h
#define CLinkedList_h

# define TRUE 1
# define FALSE 0

#include "Employee.h"

typedef Employee * LData;

typedef struct _node
{
    LData data;
    struct _node * next;
} Node;

typedef struct _linkedlist
{
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
void LInsertFront(List *plist, LData data);

int LFirst(List *plist, LData * pdata);
int LNext(List *plist, LData * pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif
