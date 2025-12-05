#include<stdio.h>
#include<math.h>
#include<string.h>
#include "stack.h"

int prefix_evaluation(char prefix[]);
int calculate(int op1, int op2, char op);
int is_operand(char ch);

int main()
{
    char prefix[] = "+-+59*4-8/62$1-73";
    int result = prefix_evaluation(prefix);
    printf("result = %d\n",result);
    return 0;
}

int prefix_evaluation(char prefix[])
{
    stack_t S;
    stack_init(&S);

    for(int i = strlen(prefix) - 1; i>=0; i--)
    {
        if(is_operand(prefix[i]))
        {
            push(prefix[i]-'0', &S);
        }
        else
        {
            int op1 = peek(&S); pop(&S);
            int op2 = peek(&S); pop(&S);
            int res = calculate(op1,op2,prefix[i]);
            push(res,&S);
            
        }
    }
    int final_res = peek(&S);
    pop(&S);
    return final_res;
}
int calculate(int op1, int op2, char op)
{
    switch (op)
    {
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '%' : return op1 % op2;
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '$' : return pow(op1, op2);
        
    }
}
int is_operand(char ch)
{
    return ch >= 48 && ch <= 57;
}