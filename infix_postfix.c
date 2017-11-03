// Converting postfix to prefix
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 500

typedef struct stack
{
    char data[MAX];
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
void stack_push(Stack* ps , char data)
{
    if(isFull(ps))
    {
        printf("Stack is full\n");
        return ;
    }
    //printf
    ps->data[++ps->top] = data;
    return ;
}

char stack_pop(Stack* ps)
{
    return ps->data[ps->top--];
}

char stack_top(Stack* ps)
{
    return ps->data[ps->top];
}
int priority(char op)
{
    if(op == '(')
        return 0;
    else if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/' || op == '%')
        return 2;
    return 3;
}
int main()
{
    Stack s;
    s.top = -1;

    char temp;
    char infix[100];
    scanf("%s",infix);

    int i=0;
    while(infix[i] != '\0')
    {   
        //printf("%c\n" , infix[i]);
      
        if(isalnum(infix[i]))
            printf("%c" , infix[i]);
        else
        {
            if(infix[i] == '(')
            {
                stack_push(&s , infix[i]);
            }
            else if(infix[i] == ')')
            {
                while(stack_top(&s) != '(')
                {
                    temp = stack_pop(&s);
                    printf("%c" , temp);
                }   
                stack_pop(&s);
            }
            else
            {   
                if(infix[i] != '$')
                {
                    while(priority(stack_top(&s)) >= priority(infix[i]))
                    {
                        temp = stack_pop(&s);
                        printf("%c" , temp);
                    }   
                    stack_push(&s , infix[i]);
                }
                else
                {
                    while(priority(stack_top(&s)) > priority(infix[i]))
                    {
                        temp = stack_pop(&s);
                        printf("%c" , temp);
                    }   
                    stack_push(&s , infix[i]);
                }
            }
        }
        i++;
    }

    while(!(isEmpty(&s)))
    {
        temp = stack_pop(&s);
        printf("%c" , temp);
    }
    
    printf("\n");
    return 0;
}