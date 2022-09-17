#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE *insert(NODE* head,int ele);
void display(NODE* head);
NODE* merge(NODE* head1,NODE* head2);

struct node *insert(NODE* head,int ele)
{
	NODE *newnode=NULL;
    NODE *current;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->info=ele;
    newnode->next=NULL;
    
    current=head;
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
    }
    return head;
}

void display(NODE* head)
{
	NODE* p=head;
	while(p!=NULL)
	{
		printf("%d-- ",p->info);
		p=p->next;
	}	
	printf("\n");
}

NODE* merge(NODE* head1,NODE* head2)
{
	if(head2==NULL)
		return head1;
	if(head1==NULL)
		return head2;
	NODE *p=head1;
	while(p->next!=NULL)
		p=p->next;
	p->next=head2;
	return head1;
}

int main()
{
	int n,ele,choice;
	NODE *head1=NULL,*head2=NULL,*head3=NULL;
    do
    {
        printf("\n1.Insert in list 1\n2.Insert in list 2\n3.Merge\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nElement: ");
            scanf("%d", &ele);
            head1 = insert(head1, ele);
            display(head1);
            break;

        case 2:
            printf("\nElement: ");
            scanf("%d", &ele);
            head2 = insert(head2, ele);
            display(head2);
            break;

        case 3:
            head3=merge(head1, head2);
            display(head3);

        case 4:
            exit(0);
            break;
        }

    } while (1);
	return 0;
}
