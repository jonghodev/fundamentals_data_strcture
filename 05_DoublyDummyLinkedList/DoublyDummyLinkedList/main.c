#include "DDBLinkedList.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    List list;
    ListInit(&list);
    
    LInsert(&list, 4);
    LInsert(&list, 5);
    
    int data;
    
    if (LFirst(&list, &data))
        printf("num: %d \n", data);
    
    if (LNext(&list, &data))
        printf("num: %d \n", data);
    
    printf("remove num: %d \n", LRemove(&list));
    printf("remove num: %d \n", LRemove(&list));
    
    return 0;
}
