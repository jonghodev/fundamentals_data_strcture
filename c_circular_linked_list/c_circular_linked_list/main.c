#include "Stack.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 5);
    SPush(&stack, 6);
    SPush(&stack, 7);
    SPush(&stack, 8);
    
    printf("%d ", SPop(&stack));
    printf("%d ", SPop(&stack));
    printf("%d ", SPop(&stack));

    return 0;
}
