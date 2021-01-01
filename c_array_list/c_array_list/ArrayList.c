#include "ArrayList.h"
#include <stdio.h>

void ListInit(List *plist)
{
    plist->numOfData = 0;
    plist->curPosition = 0;
}

void LInsert(List *plist, LData pdata)
{
    if (LIST_LEN <= plist->numOfData)
    {
        puts("You can't save");
        return;
    }
    
    plist->arr[plist->numOfData] = pdata;
    (plist->numOfData)++;
}

int LFirst(List *list, LData *pdata)
{
    if (list->numOfData == 0)
        return FALSE;
    
    list->curPosition = 0;
    *pdata = list->arr[0];
    return TRUE;
}

int LNext(List *list, LData *pdata)
{
    if (list->curPosition >= (list->numOfData) - 1)
        return FALSE;
    
    (list->curPosition)++;
    *pdata = list->arr[list->curPosition];
    return TRUE;
}

LData LRemove(List * plist)
{
    int pos = plist->curPosition;
    int num = plist->numOfData;
    LData rdata = plist->arr[pos];
    
    for (int i=pos; i<num-1; i++)
        plist->arr[i] = plist->arr[i + 1];
    
    (plist->numOfData)--;
    (plist->curPosition)--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}
