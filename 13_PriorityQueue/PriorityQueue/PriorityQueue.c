#include "PriorityQueue.h"

void PQueueInit(PQueue *ppq, PriorityComp *pc)
{
    HeapInit(ppq, pc);
}
int PQIsEmpty(PQueue *ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, PQData data)
{
    HInsert(ppq, data);
}

PQData PDequeu(PQueue *ppq)
{
    return HDelete(ppq);
}
