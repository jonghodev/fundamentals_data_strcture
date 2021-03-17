#include "PriorityQueue.h"
#include <stdio.h>

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(int argc, const char * argv[]) {
    
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);
    
    PEnqueue(&pq, 'F');
    PEnqueue(&pq, 'D');
    PEnqueue(&pq, 'Z');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'A');
    
    while(!PQIsEmpty(&pq))
        printf("%c \n", PDequeu(&pq));
    
    return 0;
}
