#include "CLinkedList.h"
#include <stdlib.h>

void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    
    (plist->numOfData)++;
}

void LInsertFront(List *plist, LData data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (plist->tail == NULL)
    {
        plist->tail=newNode;
        newNode->next=newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next=newNode;
    }
}

int LFirst(List *plist, LData * pdata)
{
    if (plist->tail == NULL)
        return FALSE;
    
    plist->before = plist->tail;
    plist->cur = plist->tail->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData * pdata)
{
    if (plist->tail == NULL)
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
    
    if (rpos == plist->tail)
    {
        if (plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }
    
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
