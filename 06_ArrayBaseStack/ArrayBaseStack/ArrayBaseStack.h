//
//  ArrayBaseStack.h
//  c_array_stack
//
//  Created by jongho on 2021/01/02.
//

#ifndef ArrayBaseStack_h
#define ArrayBaseStack_h

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

#include <stdio.h>

typedef int Data;

typedef struct _arraystack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstck);

#endif /* ArrayBaseStack_h */
