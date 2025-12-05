#include<stdio.h>
#include<math.h>
#include"stack.h"

int postfix_evaluation(char postfix[]);
int calculate(int op1, int op2, char op);
int is_operand(char ch);

int main(void)
{
    char postfix[] = "59+4862/-*-173-$+";
    int result = postfix_evaluation(postfix);
    printf("result = %d\n",result);
    return 0;
}


int postfix_evaluation(char postfix[])
{
    stack_t S;
    stack_init(&S);
    for(int i = 0; postfix[i] !=  '\0'; i++)
    {
        if(is_operand(postfix[i]))
        {
            push(postfix[i]-'0',&S);
        }
        else
        {
            int op2 = peek(&S); pop(&S);
            int op1 = peek(&S); pop(&S);
            int res = calculate(op1,op2,postfix[i]);
            push(res,&S);
        }
    }
    int final_result = peek(&S);
    pop(&S);
    return final_result;
}
int calculate(int op1, int op2, char op)
{
    switch (op)
    {
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '%' : return op1 % op2;
        case '$' : return pow(op1, op2);
    }
}
int is_operand(char ch)
{
    return ch >=48 && ch <=57;
}