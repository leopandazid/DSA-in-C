#include<stdio.h>
#include<stdlib.h>
#include"deleteAlternate.h"

int main()
{
    Node *head;
    initList(&head);

    printf("Enter Elements in the Linked List\n");
    int data;
    int choice=1;
    while(choice){
        scanf("%d",&data);
        push(&head,data);
		printf("\n enter 0 to exit 1 to continue");
        scanf("%d",&choice);
    }

    deleteAlt(&head);
    display(head);

    return 0;
}
