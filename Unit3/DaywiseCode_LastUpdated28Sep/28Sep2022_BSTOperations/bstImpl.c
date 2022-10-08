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
NODE* search(TREE *pt,int ele)
{
	NODE *r=pt->root;
	
	while(r!=NULL)
	{
		if(ele == r->info)
			return r;
		else if(ele < r->info)
			r=r->left;
		else r=r->right;
	}
	return r;		//return NULL;
}

NODE* searchRec(NODE *r,int ele)
{
	if(r==NULL)
		return r;
	else if(ele == r->info)
		return r;
	else if(ele < r->info)
		return searchRec(r->left,ele);
	else
		return searchRec(r->right,ele);
}

NODE* searchWrapper(TREE *pt,int ele)
{
	return searchRec(pt->root,ele);
}
NODE* insertNodeRec(NODE *r,NODE *newNode)
{
	if(r==NULL)
		return newNode;
	else if(newNode->info < r->info)
		r->left=insertNodeRec(r->left,newNode);
	else
		r->right=insertNodeRec(r->right,newNode);
	
	return r;
}

void insertRec(TREE *pt,int ele)
{
	NODE *newNode=createNode(ele);
	pt->root=insertNodeRec(pt->root,newNode);
}
NODE* delNode(NODE* p,int ele)
{
	NODE *q;
	if(p==NULL)
		return p;
	if(ele<p->info)
		p->left=delNode(p->left,ele);
	else if(ele > p->info)
		p->right=delNode(p->right,ele);
	else
	{
		if(p->left==NULL)	//Single right child or leaf node
		{
			q=p->right;
			free(p);
			return q;
		}
		else if(p->right==NULL)
		{
			q=p->left;
			free(p);
			return q;
		}
		else
		{
			q=p->right;
			while(q->left!=NULL)
				q=q->left;
			
			p->info=q->info;
			p->right=delNode(p->right,q->info);
		}
	}
	return p;
}
void deleteNode(TREE *pt,int ele)
{
	pt->root=delNode(pt->root,ele);
}