#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *pq)
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
    if (pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if (pos == QUE_LEN - 1)
        return 0;
    
    return pos + 1;
}

void Enqueue(Queue *pq, Data data)
{
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Out!");
        exit(-1);
    }
    
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
        printf("Queue Memory Out!");
        exit(-1);
    
    return pq->queArr[NextPosIdx(pq->front)];
}
