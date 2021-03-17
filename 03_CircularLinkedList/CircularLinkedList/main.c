#include "CLinkedList.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    List list;
    ListInit(&list);
    
    LInsert(&list, 5);
    LInsert(&list, 8);
    LInsert(&list, 7);
    LInsert(&list, 6);
    
    LData data;
    if (LFirst(&list, &data)) {
        printf("%d ", data);
        
        for (int i=0; i<10; i++)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }

    return 0;
}
