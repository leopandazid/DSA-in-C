#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"exprTree.h"

void initTree(TREE *pt)
{
	pt->root=NULL;
}
void initStack(STACK *ps)
{
	ps->top=-1;
}
void push(STACK *ps,NODE *pn)
{
	ps->s[++(ps->top)]=pn;
}

NODE* pop(STACK *ps)
{
	return ps->s[(ps->top)--];
}

void exprTree(TREE *pt,char expr[])
{
	STACK sobj;
	initStack(&sobj);
	
	for(int i=0;expr[i]!='\0';i++)
	{
		NODE *newNode=malloc(sizeof(NODE));
		newNode->info=expr[i];
		
		if(isdigit(expr[i]))
		{
			newNode->left=NULL;
			newNode->right=NULL;
			push(&sobj,newNode);
		}
		else
		{
			newNode->right=pop(&sobj);
			newNode->left=pop(&sobj);
			push(&sobj,newNode);
		}
	}
	pt->root=pop(&sobj);
}
int evalNode(NODE *r)
{
	int res;
	switch(r->info)
	{
		case '+':res=evalNode(r->left)+evalNode(r->right);
				break;
		case '-':res=evalNode(r->left)-evalNode(r->right);
				break;
		case '*':res=evalNode(r->left)*evalNode(r->right);
				break;
		case '/':res=evalNode(r->left)/evalNode(r->right);
				break;
		default: res=r->info-'0';
				break;
	}
	return res;
}

int eval(TREE *pt)
{
	return evalNode(pt->root);
}