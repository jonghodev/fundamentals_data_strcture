#include "DDBLinkedList.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    List list;
    ListInit(&list);
    
    LInsert(&list, 1);
    
    int data;
    
    if (LFirst(&list, &data))
        printf("num: %d \n", data);
    
    return 0;
}
