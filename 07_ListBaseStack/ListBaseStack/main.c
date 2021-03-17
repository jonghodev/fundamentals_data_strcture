#include "ListBaseStack.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 4);
    SPush(&stack, 5);
    SPush(&stack, 6);
    SPush(&stack, 7);
    
    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
}
