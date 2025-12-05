#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* head = NULL;
struct node* create_node();
void display(); 
void add_first(int data);
void add_last(int data);
void add_at_pos(int data, int pos);

int main(void)
{
    add_first(10);
    add_first(20);
    add_first(30);
    add_first(40);
    printf("\nAdd First:\n");
    display();  //head->40->30->20->10

    add_last(50);
    add_last(60);
    add_last(70);
    printf("\n Add last\n");
    display();
    
    return 0;
}

struct node* create_node()
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data =0;
    ptr->next =NULL;
    return ptr;
}

void add_first(int data)
{
    struct node* ptr = create_node();
    ptr->data = data;

    if(head == NULL)
    head = ptr;
    else
    {
        ptr->next= head;
        head = ptr;
    }
}

void display()
{
    if(head == NULL)
        printf("Linked list is empty \n");
    else
    {
        struct node *trav = head;
        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav= trav->next;
        } 
    }   
    printf("\n"); 
}

void add_last(int data)
{
    struct node *ptr = create_node();
    ptr->data = data;

    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *trav = head;

        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = ptr;
    }
    
}

void add_at_pos(int data, int pos)
{
    if(head == NULL)
    {
        if(pos
    }
}
