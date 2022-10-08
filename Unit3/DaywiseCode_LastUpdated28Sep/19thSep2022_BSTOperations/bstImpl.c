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

void preorder(NODE *r)
{
	if(r!=NULL)
	{
		printf("%d ",r->info);
		preorder(r->left);
		preorder(r->right);
	}
}
void preorderTraversal(TREE *pt)
{
	preorder(pt->root);
}

void inorder(NODE *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%d ",r->info);
		inorder(r->right);
	}
}
void inorderTraversal(TREE *pt)
{
	inorder(pt->root);
}
void postorder(NODE *r)
{
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d ",r->info);
	}
}
void postorderTraversal(TREE *pt)
{
	postorder(pt->root);
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