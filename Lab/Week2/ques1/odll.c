#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"odll.h"

void initList(NODE **head){
    (*head)=NULL;
}

NODE* newNode(char *srn,char *name,float cgpa){
    NODE *temp= malloc(sizeof(NODE));
    temp->s=malloc(sizeof(STUDENT));
    temp->next=NULL;
    temp->prev=NULL;
    temp->s->cgpa=cgpa;
    strcpy(temp->s->name,name);
    strcpy(temp->s->srn,srn);
    return temp;
}

int compareSRN(char *s1,char*s2){
    int k=strcmp(s1,s2);
    return k;
}

void SortedInsert(NODE **head,char *srn,char *name,float cgpa){
    NODE *node= newNode(srn,name,cgpa);

    if((*head)==NULL){

        (*head)= node;
    }
    else if (compareSRN((*head)->s->srn,node->s->srn)<0){
        // insert at head
        node->next=(*head);
        (*head)->prev= node;
        (*head)=node;
    }
    else{

        NODE *temp= (*head);
        while(temp!=NULL && compareSRN(temp->next->s->srn,node->s->srn)>0){
            temp=temp->next;
        }
        node->next=temp->next;
        node->prev= temp;
        temp->next=node;
        node->next->prev=node;
    }

}

NODE *search(NODE*head,char *srn){
    NODE *temp=head;
    while(temp !=NULL && compareSRN(srn,temp->s->srn)!=0){
        temp=temp->next;
    }
    return temp;
}

void display(NODE *p){
    printf("Name : %s",p->s->name);
    printf("CGPA : %f",p->s->cgpa);
}
