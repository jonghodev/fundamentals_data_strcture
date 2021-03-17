#include "ExpressionTree.h"
#include "LinkedListBaseStack.h"
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

BTreeNode *MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode *pnode;
    
    int expLen = strlen(exp);
    int i;
    
    StackInit(&stack);
    
    for(i=0; i<expLen; i++)
    {
        pnode = MakeBTreeNode();
        
        if(isdigit(exp[i]))
        {
            SetData(pnode, exp[i] - '0');
        }
        else
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }
        SPush(&stack, pnode);
    }
    
    return SPop(&stack);
}

int EvaluateExpTree(BTreeNode *bt)
{
    
    return 1;
}

void ShowNodeData(int data)
{
    if (0<data && data<=9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode *bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt)
{
    if (bt == NULL)
        return;
    
    if (GetLeftSubTree(bt) != NULL || GetRightSubTree(bt) != NULL)
        printf(" ( ");
    
    ShowInfixTypeExp(bt->left);
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right);
    
    if (GetLeftSubTree(bt) != NULL || GetRightSubTree(bt) != NULL)
        printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode *bt)
{
    PostorderTraverse(bt, ShowNodeData);
}

