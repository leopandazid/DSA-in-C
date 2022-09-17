#include<stdio.h>
#include<stdlib.h>
#include"stk.h"

void initStack(STACK *ps,int n)
{
	ps->top=-1;
	ps->size=n;
	ps->s=malloc(sizeof(int)*n);
}

int isFull(STACK *ps)
{
	return ps->top==ps->size-1;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}

void stackDouble(STACK *ps)
{
	ps->size=ps->size*2;
	ps->s=realloc(ps->s,ps->size*sizeof(int));
}
void push(STACK *ps,int ele)
{
	if(isFull(ps))
		stackDouble(ps);
	
	ps->top++;
	ps->s[ps->top]=ele;
	//Instead of above 2 lines
	//ps->s[++(ps->top)]=ele;
}
int pop(STACK *ps)
{
	int poppedEle=ps->s[ps->top];
	ps->top--;
	return poppedEle;
	
	//Instead of above 3 lines
	//return ps->s[ps->top--];
}
int stackTop(STACK *ps)		//Peek
{
	return ps->s[ps->top];
}
void display(STACK *ps)
{
	if(ps->top==-1)
		printf("Stack is Empty\n");
	else
	{
		for(int i=ps->top;i>=0;i--)
		{
			printf("%d ",ps->s[i]);
		}
	}
}

void destroyStack(STACK *ps)
{
	free(ps->s);
	ps->s=NULL;
	ps->top=-1;
	ps->size=0;
}