#include "stack.h"

void init_stack(stack_t *ps)
{
    ps->top =-1;
}

void push(int data, stack_t *ps)
{
    ps->top;
    ps->arr[ps->top] = data;
}
void pop(stack_t *ps)
{
    ps->arr[ps->top] = 0;
    ps->top--;
}

int peek(stack_t *ps)
{
    return ps->arr[ps->top];
}

int stack_full(stack_t *ps)
{
    return ps->top == SIZE-1;
}
int stack_empty(stack_t *ps)
{
    return ps->top == -1;
}