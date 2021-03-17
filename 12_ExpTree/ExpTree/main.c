#include <stdio.h>
#include "ExpressionTree.h"

int main(int argc, const char * argv[]) {
    char exp[] = "12+7*";
    BTreeNode *eTree = MakeExpTree(exp);
    
    printf("전위 표기법의 수식 \n");
    ShowPrefixTypeExp(eTree);
    printf("\n");
    
    printf("중위 표기법의 수식 \n");
    ShowInfixTypeExp(eTree);
    printf("\n");
    
    printf("후위 표기법의 수식 \n");
    ShowPostfixTypeExp(eTree);
    printf("\n");
    
    return 0;
}
