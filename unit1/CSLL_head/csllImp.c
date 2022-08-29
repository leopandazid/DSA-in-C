#include<stdio.h>
#include<stdlib.h>
#include"csll.h"

NODE *createNode(int data){
    NODE *temp;
    temp->info=data;
    temp->next=NULL;
    return temp;
}

void initList(CSLL *pl)
{
	pl->head=NULL;
}

void insertFront(CSLL *p1,int ele){
    NODE *newNode= createNode(ele);
    if (p1->head==NULL){
        p1->head= newNode;
    }
    else{
        newNode->next= p1->head;
        p1->head= newNode;
    }
}

void insertLast(CSLL *pl,int ele){
    NODE *newNode= createNode(ele);

    NODE *p= pl->head;
    while (p->next!= pl->head){
        p=p->next;
    }
    newNode->next= p->next;
    p->next = newNode;
}

void display(CSLL *pl){
    NODE *p= pl->head;
    while (p!= pl->head){
        print("%d \n",p->info);
        p= p->next;
    }

}

int deleteFront(CSLL *pl,int *pele){
    if (pl->head == NULL){
        return 0;
    }
    else if (pl->head->next ==pl->head){
        free(pl->head); // only one ele is present
        pl->head=NULL;
    }
    else{
        NODE* p= pl->head;
        while (p->next!= pl->head){
            p=p->next;
        }
        p->next = pl->head->next;
        p= pl->head;
        pl->head= pl->head->next;
        free(p);

    }
}
