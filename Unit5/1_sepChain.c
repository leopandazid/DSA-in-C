//Hashing: hash function key %tableSize
//Collision resolution: Separate chaining

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 7
typedef struct node
{
	int rNo;
	char name[25];
	struct node *next;
}NODE;

void initTable(NODE *ht[]);
int hashFunction(int key);
void insertRecord(NODE *ht[],int rNo,char name[]);
int deleteRecord(NODE *ht[],int rNo);
int searchRecord(NODE *ht[],int rNo,char name[]);
void display(NODE *ht[]);
void destroyTable(NODE *ht[]);

int main()
{
	NODE *ht[SIZE];
	initTable(ht);
	int choice,rNo;
	char name[25];
	
	do
	{
		printf("1.Insert 2.Delete 3.Search 4.Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter rNo\n");
					scanf("%d",&rNo);
					fflush(stdin);
					printf("Enter name\n");
					scanf("%[^\n]",name);
					insertRecord(ht,rNo,name);
					break;
			case 2:printf("Enter rNo\n");
					scanf("%d",&rNo);
					if(!deleteRecord(ht,rNo))
						printf("Record not found\n");
					break;
			case 3:printf("Enter rNo\n");
					scanf("%d",&rNo);
					if(searchRecord(ht,rNo,name))
						printf("Record found, name is %s\n",name);
					else
						printf("Record not found\n");
					break;
			case 4:display(ht);
					break;
		}
	}while(choice<5);
	destroyTable(ht);
}
void initTable(NODE *ht[])
{
	for(int i=0;i<SIZE;i++)
		ht[i]=NULL;
}
int hashFunction(int key)
{
	return key%SIZE;
}
void insertRecord(NODE *ht[],int rNo,char name[])
{
	int index=hashFunction(rNo);
	
	NODE *newNode=malloc(sizeof(NODE));
	newNode->rNo=rNo;
	strcpy(newNode->name,name);
	newNode->next=ht[index];
	ht[index]=newNode;
}
int deleteRecord(NODE *ht[],int rNo)
{
	int index=hashFunction(rNo);
	
	NODE *p=ht[index];
	NODE *q=NULL;
	
	while(p!=NULL && p->rNo!=rNo)
	{
		q=p;
		p=p->next;
	}
	if(p!=NULL)		//Record is present
	{
		if(q!=NULL)	//Not the first record
		{
			q->next=p->next;
			free(p);
		}
		else
		{
			ht[index]=p->next;
			free(p);
		}
		return 1;
	}
	return 0;
	
}
int searchRecord(NODE *ht[],int rNo,char name[])
{
	int index=hashFunction(rNo);
	
	NODE *p=ht[index];
	
	while(p!=NULL)
	{
		if(p->rNo==rNo)
		{
			strcpy(name,p->name);
			return 1;
		}
		p=p->next;
	}
	return 0;
}
void destroyTable(NODE *ht[])
{
	NODE *p,*q;
	for(int i=0;i<SIZE;i++)
	{
		p=ht[i];
		while(p!=NULL)
		{
			q=p->next;
			free(p);
			p=q;
		}
		ht[i]=NULL;
	}
}
void display(NODE *ht[])
{
	NODE *p;
	for(int i=0;i<SIZE;i++)
	{
		p=ht[i];
		printf("ht[%d]->",i);
		while(p!=NULL)
		{
			printf("%d,%s->",p->rNo,p->name);
			p=p->next;
		}
		printf("NULL\n");
	}
}