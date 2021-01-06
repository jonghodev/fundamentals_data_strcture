#include "CircularQueue.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    Queue queue;
    QueueInit(&queue);
    
    Enqueue(&queue, 1);
    Enqueue(&queue, 4);
    Enqueue(&queue, 7);
    
    while(!QIsEmpty(&queue))
        printf("%d \n", Dequeue(&queue));
    
    return 0;
}
