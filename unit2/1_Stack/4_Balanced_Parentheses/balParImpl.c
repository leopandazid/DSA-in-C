#include"balPar.h"

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
	ps->s[ps->top]=ele;
	//Instead of above 2 lines
	//ps->s[++(ps->top)]=ele;
}
char pop(STACK *ps)
{
	char poppedEle=ps->s[ps->top];
	ps->top--;
	return poppedEle;
	
	//Instead of above 3 lines
	//return ps->s[ps->top--];
}
int checkBalanceParentheses(char str[])
{
	STACK stk;
	initStack(&stk);
	
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			push(&stk,str[i]);
		else if(str[i]==')' || str[i]==']' || str[i]=='}')
		{
			if(isEmpty(&stk))
				return 0;
			else
			{
				switch(str[i])
				{
					case ')':if(pop(&stk)!='(')
								return 0;
							break;
					case ']':if(pop(&stk)!='[')
								return 0;
							break;
					case '}':if(pop(&stk)!='{')
								return 0;
							break;
				}
			}
		}
	}
	return isEmpty(&stk);
}