#include <stdio.h>
#include <string.h>
#include "stack.h"

void infix_to_prefix(char infix[], char prefix[]);
int is_operand(char ch);
int priority(char op);
void string_rev(char *str)
{
    int length = strlen(str);
    int start = 0;
    int end = length -1;
    char temp;

    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main(void)
{
    char infix[] ="5+9-4*(8-6/2)+1$(7-3)";
    char prefix[30];
    printf("Infix =%s\n",infix);
    infix_to_prefix(infix,prefix);
    printf("prefix %s \n",prefix);
    return 0;
}

void infix_to_prefix(char infix[], char prefix[])
{
    stack_t S;
    stack_init(&S);
    int j=0;
    
    for(int i = strlen(infix)-1; i >= 0; i--)
    {
        if(is_operand(infix[i]))
        {
            prefix[j++] = infix[i];

        }
        else if(infix[i] == ')')
        {
            push(')', &S);
        }
        else if(infix[i] == '(')
        {
            char ch;
            while((ch = peek(&S)) != ')')
            {
                prefix[j++] = ch;
                pop(&S);
            }
            pop(&S);
        }
        else
        {
            while(!stack_empty(&S) && priority(peek(&S)) > priority(infix[i]))
            {
                prefix[j++] = peek(&S);
                pop(&S);

            }
            push(infix[i], &S);
        }
    }
    while (!stack_empty(&S))
    {
        /* code */
        prefix[j++] = peek(&S);
        pop(&S);
    }
    prefix[j] = '\0';
    string_rev(prefix);
    
}
int is_operand(char ch)
{
    return ch >= 48 && ch <=57;
}
int priority(char op)
{
    switch (op)
    {
    case '$' :  return 10;
    case '*' :
    case '/' :
    case '%' :
                return 9;
    case '+' :
    case '-' :
                return 8;
    case ')' :
    default:
        return 0;
    }
}