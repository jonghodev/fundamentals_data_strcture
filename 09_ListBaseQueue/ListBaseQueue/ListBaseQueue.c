#include "ListBaseQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void QueueInit(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue *pq)
{
    // Front 를 가리키는 노드를 대상으로 Dequeue 가 이루어지므로 front 가 NULL 이면 Empty 로 간주한다.
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    // Empty 일 때는 rear 가 Null 이므로 분기를 건다.
    if(QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Out!");
        exit(1);
    }
    
    Node *rpos = pq->front;
    Data rdata = rpos->data;
    
    pq->front = pq->front->next;
    
    free(rpos);
    return rdata;
}

Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Out!");
        exit(1);
    }
    
    return pq->front->data;
}
