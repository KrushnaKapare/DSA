#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct stack 
{
    int arr[SIZE];
    int top;

}stack_t;

void init_stack(stack_t *ps);
void push(int data, stack_t *ps);
int peek(stack_t *ps);
int stack_empty(stack_t *ps);
void pop(stack_t *ps);
int stack_full(stack_t *ps);

int main(void)
{
    stack_t S;
    return 0;
}

void init_stack(stack_t *ps)
{
    ps->top = -1;
}
void push(int data, stack_t *ps)
{
    ps->top++;  //increment the top;
}
int peek(stack_t *ps);
int stack_empty(stack_t *ps);
void pop(stack_t *ps);
int stack_full(stack_t *ps);