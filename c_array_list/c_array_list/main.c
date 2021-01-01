#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(int argc, const char * argv[]) {
    
    List list;
    Point comPos;
    Point * ppos;
    
    ListInit(&list);
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);
    
    printf("count of list: %d \n", LCount(&list));
    
    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        
        while(LNext(&list, &ppos))
        {
            ShowPointPos(ppos);
        }
    }
    
    comPos.xpos=2;
    comPos.ypos=0;
    
    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &comPos) == 1)
        {
            ppos=LRemove(&list);
            free(ppos);
        }
        
        while(LNext(&list, &ppos))
        {
            if(PointComp(ppos, &comPos) == 1)
            {
                ppos=LRemove(&list);
                free(ppos);
            }
        }
    }
    
    printf("Rest count of list: %d \n", LCount(&list));
    
    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        
        while(LNext(&list, &ppos))
        {
            ShowPointPos(ppos);
        }
    }
    
    return 0;
}
