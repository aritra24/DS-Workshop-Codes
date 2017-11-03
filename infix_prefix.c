// Converting postfix to prefix
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 500

typedef struct stack
{
    char data[MAX];
    int top;
}Stack;
void display(Stack* ps)
{   
    int i;
    
    for(i=0 ; i <= ps->top ; i++)
        printf("%c ", ps->data[i]);
    printf("\n");
    return ;
}
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
    if(op == '(' || op == ')')
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
    char prefix[100];
    scanf("%s",infix);

    int len = strlen(infix);
    int i=0,j=0;
    for(i=0;i<len/2;i++)
    {
        temp = infix[i];
        infix[i] = infix[len-1-i];
        infix[len-1-i] = temp;
    }
    i=0;
    printf("%s\n" ,infix);
    while(i<len)
    {        
        if(isalnum(infix[i]))
        {  
            prefix[j] = infix[i];
            j++;
        }
        else
        {
            if(infix[i] == ')')
            {   
                stack_push(&s , infix[i]);
            }
            else if(infix[i] == '(')
            {
                
                while(stack_top(&s) != ')')
                {
                    temp = stack_pop(&s);
                    prefix[j] = temp;
                    j++;
                }   
                stack_pop(&s);
                
            }
            else
            {   
                if(infix[i] != '$')
                {
                    while(priority(stack_top(&s)) > priority(infix[i]))
                    {
                        temp = stack_pop(&s);
                        prefix[j] = temp;
                        j++;
                    }   
                    stack_push(&s , infix[i]);
                }
                else
                {
                    while(priority(stack_top(&s)) >= priority(infix[i]))
                    {
                        temp = stack_pop(&s);
                        prefix[j] = temp;
                        j++;
                    }   
                    stack_push(&s , infix[i]);
                }
            }
        }
        i++;;
    }

    while(!(isEmpty(&s)))
    {
        temp = stack_pop(&s);
        prefix[j] = temp;
        j++;
    }
  
    prefix[j]='\0';

    len = strlen(prefix);

    for(i=len-1 ; i>=0;i--)
    {
        printf("%c" , prefix[i]);
    }
    printf("\n");
    return 0;
}