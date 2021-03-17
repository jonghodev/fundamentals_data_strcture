//
//  LinkedListBaseStack.h
//  c_linked_list_stack
//
//  Created by jongho on 2021/01/02.
//

#ifndef LinkedListBaseStack_h
#define LinkedListBaseStack_h

#define TRUE 1
#define FALSE 0

#include "BTree.h"

typedef BTreeNode *Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _liststack
{
    Node * head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif /* LinkedListBaseStack_h */
