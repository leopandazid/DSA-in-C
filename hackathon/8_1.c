#include<stdio.h>

#define MAX 50
typedef struct tree
{
	int info;
	int used;
}TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt,int i);
void preorder(TREE *pt,int i);
void postorder(TREE *pt,int i);




void initTree(TREE *pt)
{
	for(int i=0;i<MAX;i++)
		pt[i].used=0;
}
void createTree(TREE *pt)
{
	int ele;
	int choice;
	
	printf("Enter root info\n");
	scanf("%d",&ele);
	
	pt[0].info=ele;
	pt[0].used=1;
	
	printf("Do you want to add one more node\n");
	scanf("%d",&choice);
	
	int i;
	while(choice)
	{
		i=0;
		printf("Enter the info\n");
		scanf("%d",&ele);
		
		while(i<MAX && pt[i].used)
		{
			if(ele < pt[i].info)
				i=2*i+1;
			else
				i=2*i+2;
		}
		
		if(i>=MAX)
			printf("Array index out of bound\n");
		else
		{
			pt[i].info=ele;
			pt[i].used=1;
		}
		printf("Do you want to add one more node\n");
		scanf("%d",&choice);
	}
}
void inorder(TREE *pt,int i)
{
	if(i<MAX && pt[i].used)
	{
		inorder(pt,2*i+1);
		printf("%d ",pt[i].info);
		inorder(pt,2*i+2);
	}
}
void preorder(TREE *pt,int i)
{
	if(i<MAX && pt[i].used)
	{
		printf("%d ",pt[i].info);
		preorder(pt,2*i+1);
		preorder(pt,2*i+2);
	}
}
void postorder(TREE *pt,int i)
{
	if(i<MAX && pt[i].used)
	{
		postorder(pt,2*i+1);
		postorder(pt,2*i+2);
		printf("%d ",pt[i].info);
	}
}


int main()
{
	TREE tobj[MAX]; // Array Implementation
	
	initTree(tobj);
	
	createTree(tobj);
	
	printf("Inorder traversal:");
	inorder(tobj,0);

	printf("\nPreorder traversal:");
	preorder(tobj,0);
	
	printf("\nPostorder traversal:");
	postorder(tobj,0);	
}