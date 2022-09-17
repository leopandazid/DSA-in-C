
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *prev,*next;
}NODE;

typedef struct dlist
{
	struct node* head;
}DLIST;

void init(DLIST*);
void insert(DLIST*,int);
void display(DLIST*);
int search (int value,DLIST *head, int *pos);

void initList(DLIST* pdl)
{
	pdl->head=NULL;
}

NODE* getNode(int ele)
{
	NODE* temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

void insert(DLIST* pdl,int ele)
{
	NODE* temp=getNode(ele);
	if(temp==NULL)
		return;
	NODE*p =pdl->head;
	//Empty case
	if(p==NULL)
	{
		pdl->head=temp;
		return;
	}
	//One or more nodes
	while(p->next!=NULL)
		p=p->next;
	temp->prev=p;
	p->next=temp;
}

void display(DLIST* pdl)
{
	NODE *p=pdl->head;
	if(p==NULL)
	{
		printf("Empty List\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d-- ",p->info);
		p=p->next;
	}
	printf("\n");
}

int search (int value, DLIST *pdl, int *pos)
{
    NODE *p=pdl->head;
    int c=0;
    if(p->info==value){
        *pos = c;
        return;
    }
    while(p!=NULL)
    {
        if (value==p -> info)
        {
            printf("Element Found\n");
            printf("Position = %d\n",c);
            return 1;
        }
        p=p->next;
        c+=1;
    }
    if(p==NULL){
        printf("\nnot found\n");
        return;
    }
    *pos=c;
    return 0;
}

int main()
{
	DLIST head;
	initList(&head);
	int choice,ele,givenEle,res,value;
    int pos=0;
	
	do{
		printf("1.Insert\n2.Search\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
				case 1:printf("Enter an integer\n");
						scanf("%d",&ele);
						insert(&head,ele);
                        display(&head);
						break;
                
                case 2:printf("Enter Value\n");
                        scanf("%d",&value);
                        search (value,&head,&pos);
				
				case 3:display(&head);
						break;
				case 4:exit(0);
				
		}
	}while(1);
	
	return 0;
}