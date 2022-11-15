// 5) Convert the given valid infix expression to postfix.
#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}

/*#include<ctype.h>
#include"infixToPostfix.h"

void initStack(STACK *ps)
{
	ps->top=-1;
}
int isFull(STACK *ps)
{
	return ps->top==MAX-1;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}
void push(STACK *ps,char ele)
{
	ps->top++;
	ps->a[ps->top]=ele;
	
	//ps->a[++(ps->top)]=ele;
}
char pop(STACK *ps)
{
	char poppedEle=ps->a[ps->top];
	ps->top--;
	
	return poppedEle;
	
	//return ps->a[ps->top--];
}
char stackTop(STACK *ps)
{
	return ps->a[ps->top];
}

int precedence(char st,char in)
{
	switch(in)
	{
		case '+':
		case '-':if(st=='(')
					return 0;
				else 
					return 1;
				
		case '*':
		case '/':if(st=='+' || st=='-' || st=='(')
					return 0;
				else
					return 1;
		case '(':return 0;
		
		case ')':if(st=='(')
					return 0;
				else
					return 1;
	}
}
void infixToPostfix(char infix[],char postfix[])
{
	STACK s;
	
	initStack(&s);
	
	int j=0;
	for(int i=0;infix[i]!='\0';i++)
	{
		if(isdigit(infix[i]))
			postfix[j++]=infix[i];
		else
		{
			while(!isEmpty(&s) && precedence(stackTop(&s),infix[i]))
				postfix[j++]=pop(&s);
			
			if(infix[i]==')')
				pop(&s);
			else
				push(&s,infix[i]);
		}
	}
	while(!isEmpty(&s))
		postfix[j++]=pop(&s);
	postfix[j]='\0';
}
Footer
© 2022 GitHub, Inc.*/