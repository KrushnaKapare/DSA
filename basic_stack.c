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
    init_stack(&S);
    int choice;
    
    do
    {
        printf("0.Exit\n1.Push\n2.Pop\n3.peek\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0: 
                    exit(0);
            case 1: //push
                    if(stack_full(&S))
                    {
                        printf("Stack is full\n");
                    
                    }
                    else
                    {
                        int data;
                        printf("Enter the data to push :");
                        scanf("%d", &data);
                        push(data,&S);
                        printf("Data Pushed = %d\n",data);
                    }
                    break;
            case 2: //pop
                    if(stack_empty(&S))
                    {
                        printf("stack is empty\n");
                    }
                    else
                    {
                        int val = peek(&S);
                        pop(&S);
                        printf("Value popped = %d\n",val);
                    }
                    break;
            case 3: //peek
                    if(stack_empty(&S))
                    {
                        printf("Stack empty ! peek not possible\n");
                    }
                    else
                    {
                        int val = peek(&S);
                        printf("Topmost value = %d\n",val);
                    }
                    break;
            default:
                    printf("Invalid Choice!");
        }
    } while (choice != 0);
    
 
    return 0;
}

void init_stack(stack_t *ps)
{
    ps->top = -1;
}
void push(int data, stack_t *ps)
{
    ps->top++;  //increment the top;

    ps->arr[ps->top] = data;    // insert the data at the top index

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
