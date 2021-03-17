#include "Deque.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if (pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = pdeq->head;
    
    if (DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;
    
    pdeq->head = newNode;
}
void DQAddLast(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = pdeq->tail;
    
    
    if (DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;
    
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Queue Memory Out!");
        exit(1);
    }
    
    Node *rpos = pdeq->head;
    Data rdata = rpos->data;
    
    pdeq->head = pdeq->head->next;
    free(rpos);
    
    if(pdeq->head == NULL)
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;
    
    return rdata;
}

Data DQRemoveLast(Deque *pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Queue Memory Out!");
        exit(1);
    }
    
    Node *rpos = pdeq->tail;
    Data rdata = rpos->data;
    
    pdeq->tail = pdeq->tail->prev;
    free(rpos);
    
    if(pdeq->tail == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;
    
    return rdata;
}

Data DQGetFirst(Deque *pdeq)
{
    return pdeq->head->data;
}

Data DQGetLast(Deque *pdeq)
{
    return pdeq->tail->data;
}
