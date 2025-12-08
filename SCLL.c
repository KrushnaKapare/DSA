#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;

node* create_node();
void add_first(int data);
void display();
void add_last();
void delete_first();
void delete_last();

int main(void)
{
    add_first(11);
    add_first(22);
    add_first(33);
    printf("\n Add first\n");
    display();
    
    add_last(44);
    add_last(55);
    add_last(66);
    printf("\n add last\n");
    display();

    delete_first();
    printf("\n delete first\n");
    display();

    delete_last();
    printf("\n delete last \n");
    display();

    return 0;
}
node* create_node()
{
    node* ptr = (node*) malloc(sizeof(node));
    ptr->next = NULL;
    ptr->data = 0;
    
    return ptr;
}

void add_first(int data)
{
    node *new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = new_node;
    }
    else
    {
        struct node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
            
        }
        new_node->next = head;
        head = new_node;
        trav->next = head;
    }
}

void display()
{
    if(head == NULL)
        printf("list is empty\n");
    else
        printf("Head");
        struct node *trav = head;
        do{
            printf("=>%d",trav->data);
            trav = trav->next;
        }while(trav != head);
}

void add_last(int data)
{
    node *new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = new_node;

    }
    else
    {
        struct node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = new_node;
        new_node->next = head;
    }
}

void delete_first()
{
    if(head==NULL)
        printf("list is empty\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else{
        struct node *trav = head;
        while(trav->next != head)
            trav = trav->next;
        
        struct node *temp = head;
        head = temp->next;
        trav->next= head;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is empty\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else{
        struct node *trav = head;
        while(trav->next->next != head)
            trav = trav->next;
        
        free(trav->next);
        trav->next = head;
    }
}