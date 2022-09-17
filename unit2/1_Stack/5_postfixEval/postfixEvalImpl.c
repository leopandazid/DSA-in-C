#include<ctype.h>
#include<limits.h>
#include"postfixEval.h"

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

int postfixEval(char str[])
{
	STACK stk;
	initStack(&stk);
	
	for(int i=0;str[i]!='\0';i++)
	{
		if(isdigit(str[i]))
			push(&stk,str[i]-'0');
		else
		{
			int op2=pop(&stk);
			int op1=pop(&stk);
			
			int res;
			switch(str[i])
			{
				case '+':res=op1+op2;
							break;
							
				case '-':res=op1-op2;
							break;
							
				case '*':res=op1*op2;
							break;	

				case '/':if(op2==0)
							return INT_MAX;
						else
							res=op1/op2;
							break;			
			}
			push(&stk,res);
		}
	}
	return pop(&stk);
}