#include <ctype.h>
#include <stdio.h>

#define MAX 30

typedef struct stack
{
    int top;
    char a[MAX];
} STACK;

void initStack(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps, char ele);
char pop(STACK *ps);
char stackTop(STACK *ps);
int precedence(char st, char in);
void infixToPostfix(char infix[], char postfix[]);

void initStack(STACK *ps)
{
    ps->top = -1;
}
int isFull(STACK *ps)
{
    return ps->top == MAX - 1;
}
int isEmpty(STACK *ps)
{
    return ps->top == -1;
}
void push(STACK *ps, char ele)
{
    ps->top++;
    ps->a[ps->top] = ele;

    // ps->a[++(ps->top)]=ele;
}
char pop(STACK *ps)
{
    char poppedEle = ps->a[ps->top];
    ps->top--;

    return poppedEle;

    // return ps->a[ps->top--];
}
char stackTop(STACK *ps)
{
    return ps->a[ps->top];
}

int precedence(char st, char in)
{
    switch (in)
    {
    case '+':
    case '-':
        if (st == '(')
            return 0;
        else
            return 1;

    case '*':
    case '/':
        if (st == '+' || st == '-' || st == '(')
            return 0;
        else
            return 1;
    case '(':
        return 0;

    case ')':
        if (st == '(')
            return 0;
        else
            return 1;
    }
}
void infixToPostfix(char infix[], char postfix[])
{
    STACK s;

    initStack(&s);

    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]))
            postfix[j++] = infix[i];
        else
        {
            while (!isEmpty(&s) && precedence(stackTop(&s), infix[i]))
                postfix[j++] = pop(&s);

            if (infix[i] == ')')
                pop(&s);
            else
                push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s))
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

int main()
{
    char infix[30], postfix[30];

    printf("Enter a valid infix expression\n");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
}