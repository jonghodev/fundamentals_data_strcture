#include "InfixToPostfix.h"
#include "PostCalculator.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    char exp1[] = "1+2*3";
    
    ConvertToRPNExp(exp1);
    printf("%d \n", EvalRPNExp(exp1));
    
    return 0;
}
