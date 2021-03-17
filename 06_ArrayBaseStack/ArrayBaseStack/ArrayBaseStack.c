//
//  ArrayBaseStack.c
//  c_array_stack
//
//  Created by jongho on 2021/01/02.
//

#include "ArrayBaseStack.h"
#include <stdlib.h>

void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    (pstack->topIndex)++;
    pstack->stackArr[pstack->topIndex] = data;
        
}

Data SPop(Stack *pstack)
{
    if(SIsEmpty(pstack)) {
        printf("Out of stack memory!");
        exit(-1);
    }
    int rIdx = pstack->topIndex;
    (pstack->topIndex)--;
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack)
{
    if(SIsEmpty(pstack)){
        printf("Out of stack memory!");
        exit(-1);
    }
    return pstack->stackArr[pstack->topIndex];
}
