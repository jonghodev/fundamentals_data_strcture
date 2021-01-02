#include "DLinkedList.h"
#include <stdlib.h>

void FInsert(List *plist, LData data);

void SInsert(List *plist, LData data);

void ListInit(List *plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data)
{
    if (plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

void FInsert(List *plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head->next;
    plist->head->next=newNode;
    
    (plist->numOfData)++;
}

void SInsert(List *plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    Node * pred = plist->head;
    while (pred->next != NULL && plist->comp(data, pred->next->data))
        pred = pred->next;
    
    newNode->next = pred->next;
    pred->next = newNode;
    (plist->numOfData)++;
}

int LFirst(List *plist, LData * pdata)
{
    if (plist->head->next == NULL)
        return FALSE;
    
    plist->before = plist->head;
    plist->cur = plist->head->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData * pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist)
{
    Node * rpos = plist->cur;
    LData rdata = rpos->data;
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    (plist->numOfData)--;
    free(rpos);
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}
