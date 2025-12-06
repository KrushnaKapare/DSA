#include<stdio.h>
#include "stack.h"

int is_operand(char ch);
int priority(char op);
void infix_to_postfix(char infix[], char postfix[]);

int main()
{
    char infix[] = "5+9-4*(8-6/2)+1$(7-3)";
    char postfix[30];
    printf("infix = %s\n",infix);
    infix_to_postfix(infix,postfix);
    printf("postfix = %s\n",postfix);
    return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    stack_t S;
    init_stack(&S);
    int j =0;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        if(is_operand(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '(')
        {
            push('(', &S);
        }
        else if(infix[i] == ')')
        {
            char ch;
            while((ch = peek(&S)) != '(')
            {
                postfix[j++] = ch;
                pop(&S);
            }
            pop(&S);
        }
        else
        {
           while (!stack_empty(&S) && priority(peek(&S)) >= priority(infix[i]))
           {
                postfix[j++] = peek(&S);
                pop(&S);
           }
           push(infix[i],&S);
           
        }

    }
    while(!stack_empty(&S))
    {
        postfix[j++] = peek(&S);
        pop(&S);
    }
    postfix[j] ='\0';
}

int is_operand(char ch)
{
    return ch >= 48 && ch <=57;
}

int priority(char op)
{
    switch (op)
    {
        
        case '$' : return 10;
        case '*' : 
        case '/' : 
        case '%' :
                    return 9;
        case '+' : 
        case '-' :
                    return 8;
        case '(' :
        default:
                    return 0;        
    }
}