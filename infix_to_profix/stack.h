#define SIZE 20

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack_t;

void init_stack(stack_t *ps);
void push(int data, stack_t *ps);
void pop(stack_t *ps);
int peek(stack_t *ps);
int stack_empty(stack_t *ps);
int stack_full(stack_t *ps);
