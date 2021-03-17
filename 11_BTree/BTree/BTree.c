#include "BTree.h"
#include <stdlib.h>
#include <stdio.h>

BTreeNode * MakeBTreeNode(void)
{
    BTreeNode *bt = (BTreeNode*)malloc(sizeof(BTreeNode));
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

BTData GetData(BTreeNode *bt)
{
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}


BTreeNode * GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->right = sub;
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;
    
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;
    
    PreorderTraverse(bt->left, action);
    action(bt->data);
    PreorderTraverse(bt->right, action);
}

void PosteorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;
    
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode *bt)
{
    if (bt == NULL)
        return;
    
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    
    printf("del tree data: %d \n", bt->data);
    free(bt);
}
