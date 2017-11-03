// Implementing a stack using singly linked list 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

// Push
Node* stack_push(Node* head , int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node -> data = data;

    if(head == NULL)
    {   
        head = new_node;
        new_node->next = NULL;
        return head;
    }

    Node* iter = head;

    while(iter -> next != NULL)
    {   
        iter = iter -> next;
    }

    iter -> next = new_node;
    new_node->next = NULL;
    return head;
}

Node* stack_pop(Node* head)
{
    if(head == NULL)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    else if(head -> next == NULL)
    {
        printf("Popping element %d\n" , head -> data);
        printf("Returning");
        return NULL;
    }


    Node* iter = head;
    Node* prev = NULL;
    while(iter->next != NULL)
    {
        prev = iter;
        iter = iter -> next;
    }

    printf("Popping element %d\n" , iter -> data);    
    free(iter);
    prev->next = NULL;
    return head;
}
void display(Node* head)
{   
    if(head == NULL)
    {
       printf("Stack empty");
    }
    Node* iter = head;

    while(iter -> next != NULL)
    {
        printf("%d ", iter->data);
        iter = iter -> next;
    }

    printf("%d\n", iter->data);
    return ;
}
int main()
{
    Node* head = NULL;
    int flag=1;
    int selection;
    int data;

    while(flag)
    {
        printf("Select an operation\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&selection);

        switch(selection)
        {
            case 1:
                printf("Enter new element\n");
                scanf("%d",&data);
                head = stack_push(head , data);
                break;
            case 2:
                printf("Popping....\n");
                head = stack_pop(head);
                break;
            case 3:
                printf("Displaying stack");
                display(head);
                break;
            case 4:
                flag = 0;
        }
    }

    return 0;
}