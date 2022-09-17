#include<stdio.h>
#include"stk.h"

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

void push(STACK *ps,int ele)
{
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