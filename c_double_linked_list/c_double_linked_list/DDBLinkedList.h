#ifndef DDBLinkedList_h
#define DDBLinkedList_h

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _DLinkedList
{
    Node *head;
    Node *tail;
    Node *cur;
    int numOfData;
} DDBLinkedList;

typedef DDBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);

int LFirst(List *plist, Data * pdata);
int LNext(List *plist, Data * pdata);

Data LRemove(List *plist);
int LCount(List *plist);

#endif
