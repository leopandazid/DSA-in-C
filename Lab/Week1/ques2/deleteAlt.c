#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int key;
    struct node* link;
}node_t;


typedef struct list{
    node_t* h;
}list_t;


void display(list_t* p_list){
    if(p_list->h== NULL){
        printf("\n\nNo elements in the list\n");
    }
    else{
        node_t* temp = (node_t*)malloc(sizeof(node_t));
        temp = p_list->h;
        printf("The elements are: ");
        while(temp != NULL){
            printf("%d ",temp->key);
            temp = temp->link;
        }
        printf("\n\n\n");
    }
}


void init_list(list_t* p_list){
    p_list->h = NULL;
}

void insert_head(list_t* p_list, int data){
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->key = data;
    temp->link = NULL;
    if(p_list->h == NULL){
        p_list->h = temp;
    }
    else{
        temp->link = p_list->h;
        p_list->h = temp;
    }
}

void del_alt(list_t* p_list)
{
    if(p_list->h == NULL)
    {
        printf("The list is empty\n");
    }
    else
    { /*initialzing node to be deleted*/
        node_t* pres;
        node_t* prev;
        pres = p_list->h;
        prev = NULL;
        while(pres != NULL)
        {
            if(prev == NULL) /* Deleting first element */
            {          
                p_list->h = pres->link;
            }
            else
            {
                prev->link = pres->link;
            }
            
            prev = pres;
            pres = pres->link; /* changing link */
        }
    }
}


int main()
{
    list_t l;
    init_list(&l);
    int choice, ele;
    while(1)
    {
        display(&l);
        printf("1) Insert at head\n");
        printf("2) Delete alternate nodes\n");
        printf("3) Quit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element: ");
                scanf("%d",&ele);
                printf("\n\n");
                insert_head(&l,ele);
                break;
            case 2:
                del_alt(&l);
                break;
            case 3:
            	exit(0);
            	break;
            default:
            	printf("Invalid Choice \n");
            	break;
            	
        }
    }
}