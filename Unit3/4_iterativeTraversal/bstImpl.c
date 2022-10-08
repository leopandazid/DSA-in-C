#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

void initTree(TREE *pt)
{
	pt->root=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}
void insertNode(TREE *pt,int ele)
{
	NODE *newNode=createNode(ele);
	
	NODE *p=pt->root;
	NODE *q=NULL;
	
	if(pt->root==NULL)
	{
		pt->root=newNode;
	}
	else
	{
		while(p!=NULL)
		{
			q=p;
			
			if(newNode->info < p->info)
				p=p->left;
			else
				p=p->right;
		}
		if(newNode->info < q->info)
			q->left=newNode;
		else
			q->right=newNode;
	}
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

int isEmpty(STACK *ps)
{
	return ps->top==-1;
}

void preorderTraversal(TREE *pt)
{
	STACK s;
	initStack(&s);
	
	NODE *cur=pt->root;
	
	push(&s,cur);
	
	while(!isEmpty(&s))
	{
		cur=pop(&s);
		printf("%d ",cur->info);
		
		if(cur->right!=NULL)
			push(&s,cur->right);
		if(cur->left!=NULL)
			push(&s,cur->left);
	}
}

void inorderTraversal(TREE *pt)
{
	STACK s;
	initStack(&s);
	
	NODE *cur=pt->root;
	while(cur!=NULL || !isEmpty(&s))
	{
		if(cur!=NULL)
		{
			push(&s,cur);
			cur=cur->left;
		}
		else
		{
			cur=pop(&s);
			printf("%d ",cur->info);
			cur=cur->right;
		}
	}
}

void postorderTraversal(TREE *pt)
{
	if(pt->root==NULL)
		return;
	STACK s1,s2;
	initStack(&s1);
	initStack(&s2);
	NODE *cur=pt->root;
	push(&s1,cur);
	while(!isEmpty(&s1))
	{
		cur=pop(&s1);
		
		push(&s1,cur);
		
		if(cur->left!=NULL)
			push(&s1,cur->left);
		
		if(cur->right!=NULL)
			push(&s1,cur->right);
	}
	while(!isEmpty(&s2))
	{
		cur=pop(&s2);
		printf("%d ",cur->info);
	}
}

void initQueue(QUEUE *pq)
{
	pq->front=0;
	pq->rear=-1;
}
void enqueue(QUEUE *pq,NODE* ele)
{
	pq->a[++pq->rear]=ele;
}
NODE* dequeue(QUEUE *pq)
{
	return pq->a[pq->front++];	
}

int isEmptyQ(QUEUE *pq)
{
	return pq->front>pq->rear;
}
void levelOrderTraversal(TREE *pt)
{
	QUEUE qobj;
	initQueue(&qobj);
	NODE *cur=pt->root;
	
	if(cur==NULL)
		return;
	
	enqueue(&qobj,cur);
	while(!isEmptyQ(&qobj))
	{
		cur=dequeue(&qobj);
		printf("%d ",cur->info);
		if(cur->left!=NULL)
			enqueue(&qobj,cur->left);
		if(cur->right!=NULL)
			enqueue(&qobj,cur->right);
	}
	
}
void destroyNode(NODE *r)
{
	if(r!=NULL)
	{
		destroyNode(r->left);
		destroyNode(r->right);
		printf("%d freed\n",r->info);
		free(r);
	}
}
void destroyTree(TREE *pt)
{
	destroyNode(pt->root);
	pt->root=NULL;
}