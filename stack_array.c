// Implementing a stack using singly linked list 
#include<stdio.h>
#include<stdlib.h>

#define MAX 500

typedef struct stack
{
    int data[MAX];
    int top;
}Stack;

int isFull(Stack* ps)
{
    if(ps->top == MAX-1)
        return 1;
    return 0;
}
int isEmpty(Stack* ps)
{
    if(ps->top == -1)
        return 1;
    return 0;
}
// Push
void stack_push(Stack* ps , int data)
{
    if(isFull(ps))
    {
        printf("Stack is full\n");
        return ;
    }
    
    ps->data[++ps->top] = data;
    return ;
}

void stack_pop(Stack* ps)
{
    if(isEmpty(ps))
    {
        printf("Stack is empty\n");
        return ;
    }
    
    printf("Popping from stack : %d\n" , ps->data[ps->top]);
    ps->top--;
    return ;
}
void display(Stack* ps)
{   
    int i;
    
    for(i=0 ; i <= ps->top ; i++)
        printf("%d ", ps->data[i]);
    printf("\n");
    return ;
}
int main()
{
    Stack s;
    s.top = -1;

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
                stack_push(&s, data);
                break;
            case 2:
                printf("Popping....\n");
                stack_pop(&s);
                break;
            case 3:
                printf("Displaying stack");
                display(&s);
                break;
            case 4:
                flag = 0;
        }
    }

    return 0;
}