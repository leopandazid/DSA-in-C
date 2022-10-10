//Right in threaded binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *left;
	struct node *right;
	int rThread;
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;
void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt);

int main()
{
	TREE tobj;
	
	initTree(&tobj);
	createTree(&tobj);
	printf("Inorder Traversal\n");
	inorder(&tobj);
}

void initTree(TREE *pt)
{
	pt->root=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->left=newNode->right=NULL;
	newNode->rThread=1;
	
	return newNode;
}
void setLeft(NODE *cur,NODE *newNode)
{
	newNode->right=cur;
	cur->left=newNode;
}
void setRight(NODE *cur,NODE *newNode)
{
	newNode->right=cur->right;
	cur->right=newNode;
	cur->rThread=0;
}
void createTree(TREE *pt)
{
	int ele,choice;
	printf("Enter root info\n");
	scanf("%d",&ele);
	
	NODE *newNode=createNode(ele);
	pt->root=newNode;
	
	printf("Do you want to add one more node\n");
	scanf("%d",&choice);
	
	NODE *p=NULL,*q=NULL;
	while(choice)
	{
		p=pt->root;
		printf("Enter node info\n");
		scanf("%d",&ele);
		
		newNode=createNode(ele);
		
		while(p!=NULL)
		{
			q=p;
			
			if(newNode->info < p->info)
				p=p->left;
			else if(p->rThread)
				break;
			else
				p=p->right;
		}
		if(p==NULL)
			setLeft(q,newNode);
		else
			setRight(p,newNode);
		printf("Do you want to add one more node\n");
		scanf("%d",&choice);
	}
}
void inorder(TREE *pt)
{
	NODE *p=pt->root;
	NODE *q=NULL;
	
	while(p!=NULL)
	{
		q=NULL;
		
		while(p!=NULL)
		{
			q=p;
			p=p->left;
		}
		
		printf("%d ",q->info);
		p=q->right;
		
		while(q->rThread && p!=NULL)
		{
			printf("%d ",p->info);
			q=p;
			p=p->right;
		}
	}
}