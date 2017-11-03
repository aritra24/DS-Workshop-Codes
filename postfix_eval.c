// Postfix Evalutaion using stacks
#include<stdio.h>
#include<math.h>
#include<ctype.h>
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

int stack_pop(Stack* ps)
{
    return ps->data[ps->top--];
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

    char infix[100];
    scanf("%s",infix);

    int i=0 , temp;
    int op1 , op2;

    while(infix[i] != '\0')
    {   
        if(isdigit(infix[i]))
            stack_push(&s , infix[i] - '0');
        else
        {
            op2 = stack_pop(&s);
            op1 = stack_pop(&s);

            switch(infix[i])
            {
                case '+':
                    temp = op1 + op2;
                    stack_push(&s,temp);
                    break;
                case '-' :
                    temp = op1 - op2;
                    stack_push(&s,temp);
                    break;
                case '*' :
                    temp = op1 * op2;
                    stack_push(&s,temp);
                    break;
                case '/' :
                    temp = op1 / op2;
                    stack_push(&s,temp);
                    break;
                case '%' :
                    temp = op1 % op2;
                    stack_push(&s,temp);
                    break;
                case '$' :
                    temp = pow(op1 ,op2);
                    stack_push(&s,temp);
                    break;  
            }
        }
        i++;
    }

    int answer = stack_pop(&s);
    printf("The result of Postfix Evaluation is %d\n" , answer);
    return 0;
}