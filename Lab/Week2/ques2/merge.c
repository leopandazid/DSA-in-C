/*
2)Merge 2 ordered lists and display the merged list
*/
/*
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
void display(struct Node *p)
{
    if(p==NULL)
    printf("The list is empty\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->link;
        }
        printf("\n");
    }
}
void merge(struct Node **p,struct Node **q)
{
    struct Node *pres;
    pres=*p;
    if(*p==NULL)
    {
        *p=*q;
    }
    else
    {
    while(pres->link!=NULL)
    {
        pres=pres->link;
    }
    pres->link=*q;
}
}
void insert(struct Node **p,int x)
{

    struct Node *prev,*pres;
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=NULL;
    prev=NULL;
    pres=*p;
    while(pres!=NULL && x>pres->data)
    {
        prev=pres;
        pres=pres->link;
    }
    if(pres!=NULL)
    {
        if(prev==NULL)
        {   temp->link=*p;
            *p=temp;
        }
        else
        {
            prev->link=temp;
            temp->link=pres;
        }
    }

        else
        {
            if(prev==NULL)
            {

                temp->link=*p;
                *p=temp;
            }
            else{
                prev->link=temp;
            }
        }
    }

void sort(struct Node **p)
{
    struct Node *pres;
    pres=*p;
    while(pres!=NULL)
    {
        if(pres->data<pres->link->data)
        pres=pres->link;
        else
        {

        }
    }
}
int main()
{
    int n,ch;
    struct Node *first;
    struct Node *second;
    first=NULL;
    second=NULL;
    while(1)
    {   printf("The first node :\n");
        display(first);
        printf("The second node :\n");
        display(second);
    printf("Enter 1 to insert the elements in the first list , 2 to insert elements in the second list and 3 to exit from the program\n");
    scanf("%d",&ch);
        if(ch==1)
        {
        printf("Enter the element to be inserted in the first list\n");
        scanf("%d",&n);
        insert(&first,n);
         }
         else if(ch==2)
         {
        printf("Enter the element to be inserted in the second list\n");
        scanf("%d",&n);
        insert(&second,n);
         }
         else
         {
            break;
         }
    }
    merge(&first,&second);
    printf("The merged list is \n");
    display(first);
    sort(&first);
}
*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next, *prev;
};
void create(struct Node **p, int n);
void merge(struct Node **p, struct Node **q, struct Node **r);
void merge(struct Node **p, struct Node **q, struct Node **r)
{
    struct Node *pres1, *pres2;
    pres1 = *p;
    pres2 = *q;
    while (pres1 != NULL)
    {
        create(r, pres1->data);
        pres1 = pres1->next;
    }
    while (pres2 != NULL)
    {
        create(r, pres2->data);
        pres2 = pres2->next;
    }
}
void create(struct Node **p, int n)
{
    struct Node *temp, *pres;
    temp = (struct Node *)malloc(sizeof(struct Node));
    pres = *p;
    temp->data = n;
    temp->prev = NULL;
    temp->next = NULL;
    if (*p == NULL)
    {
        *p = temp;
    }
    else
    {
        while (pres->next != NULL && n > pres->data)
        {
            pres = pres->next;
        }
        if (n <= pres->data)
        {
            if (pres->prev == NULL)
            {
                temp->next = pres;
                pres->prev = temp;
                *p = temp;
            }
            else
            {
                pres->prev->next = temp;
                temp->prev = pres->prev;
                pres->prev = temp;
                temp->next = pres;
            }
        }
        else
        {
            pres->next = temp;
            temp->prev = pres;
        }
    }
}
void display(struct Node *p)
{
    if (p == NULL)
        printf("List is empty\n");
    else
    {
        while (p != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
    }
}
int main()
{
    struct Node *pl1, *pl2, *pl3;
    int x, ch;
    pl1 = NULL;
    pl2 = NULL;
    pl3 = NULL;
    do
    {
        printf("\n0: exit\n1: Enter value to list 1\n2 :Enter value to list 2\n3: merge\n4 : display list1\n5 : display list2\n6 : display list3\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value of x : ");
            scanf("%d", &x);
            create(&pl1, x);
            break;
        case 2:
            printf("Enter value of x : ");
            scanf("%d", &x);
            create(&pl2, x);
            break;
        case 3:
            merge(&pl1, &pl2, &pl3);
            break;
        case 4:
            display(pl1);
            break;
        case 5:
            display(pl2);
            break;
        case 6:
            display(pl3);
            break;
        }
    } while (ch != 0);
    return 0;
}