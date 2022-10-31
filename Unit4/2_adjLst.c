#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initGraph(NODE *V[MAX]);
void createGraph(NODE *V[MAX],int n);
void displayGraph(NODE *V[MAX],int n);
void destroyGraph(NODE *V[MAX],int n);

int main()
{
	NODE *V[MAX];
	int n;
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	initGraph(V);
	createGraph(V,n);
	
	displayGraph(V,n);
	destroyGraph(V,n);
}

void initGraph(NODE *V[MAX])
{
	for(int i=0;i<MAX;i++)
		V[i]=NULL;
}
void addEdge(NODE *V[MAX],int src,int dest)
{
	NODE *newNode=malloc(sizeof(newNode));
	
	newNode->info=dest;
	newNode->next=V[src];
	V[src]=newNode;
}
void createGraph(NODE *V[MAX],int n)
{
	printf("Enter -1 -1 to stop adding edges\n");
	int src,dest;
	while(1)
	{
		scanf("%d%d",&src,&dest);
		if(src<0 || dest<0 || src>=n || dest >=n)
			break;
		addEdge(V,src,dest);
	}
}
void displayGraph(NODE *V[MAX],int n)
{
	NODE *p;
	for(int i=0;i<n;i++)
	{
		p=V[i];
		printf("V[%d]->",i);
		while(p!=NULL)
		{
			printf("%d->",p->info);
			p=p->next;
		}
		printf("NULL\n");
	}
}
void destroyGraph(NODE *V[MAX],int n)
{
	NODE *p,*q;
	for(int i=0;i<n;i++)
	{
		p=V[i];
		while(p!=NULL)
		{
			q=p;
			p=p->next;
			free(q);
		}
		V[i]=NULL;
	}
}