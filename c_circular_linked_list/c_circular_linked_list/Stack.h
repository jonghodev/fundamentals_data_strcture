//
//  Stack.h
//  c_circular_linked_list
//
//  Created by jongho on 2021/01/02.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include "CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _stack
{
    List * plist;
} stack;

typedef stack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);

Data SPeek(Stack *pstack);


#endif
