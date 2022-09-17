#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"odll.h"

int main(int argc, char const *argv[])
{
    int choice;

    NODE *head;
    initList(&head);
    float cgpa;
    char name[30];
    char srn[14];
    do{
        printf("1. Insert in DLL\n");
        printf("2. Search in DLL\n");
        printf("3. Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                
                printf("Enter Name : ");
                scanf("%s",name);
                printf("Enter SRN : ");
                scanf("%s",srn);
                printf("Enter CGPA : ");
                scanf("%f",&cgpa);
                SortedInsert(&head,srn,name,cgpa);      
                break;
            case 2:
                printf("Enter SRN to be searched : ");
                scanf("%s",srn);
                NODE *temp = search(head,srn);
                display(temp);
                break;
            case 3:
                exit(0);

        }

    }while (choice<3 && choice>0);
    return 0;
}
