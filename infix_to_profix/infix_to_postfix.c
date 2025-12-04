#include<stdio.h>
#include "stack.h"

int is_operand(char ch);
int priority(char op);
void infix_to_postfix(char infix[], char postfix[]);

int main()
{
    char infix[] = "5+9-4*(8-6/2)+1$(7-3)";
    char postfix[30];
    return 0;
}

void in_to_post(char infix[], char postfix[])
{
    stack_t S;
    init_stack(&S);
    int j =0;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        
    }
}