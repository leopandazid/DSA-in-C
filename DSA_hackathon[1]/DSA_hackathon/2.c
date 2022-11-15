// 2) Reverse the given singly linked list.

#include <stdio.h>
#include <stdlib.h>
 
/* symbolic constants declared */
#define TRAVERSE 1
#define INSERT 2
#define REVERSE  3
#define QUIT   4
 
/* structure declaration */
typedef struct  NODE {
                      int data;
                      struct NODE *link;
        } Node;
 
void insert_sll(Node **, const int);
void traverse_sll(Node **);
void reverse_sll(Node **);
 
int main(void)
{
    Node *root = 0;         /* root is NULL */
    Node **ptr = &root;     /* pointer-to-root */
    int value;
    int op;
 
     puts("\n**Let's create a Singly Linked List**\n");
    printf("User, enter 1 for TRAVERSE, 2 FOR INSERT , 3 for REVERSE and 4 for QUIT  : ");
    while (1) {
        while (scanf("%d", &op) == 1 &&
               (op == INSERT || op == QUIT || op == TRAVERSE||op==REVERSE)) {
 
            if (op == TRAVERSE) {
                traverse_sll(ptr);
            }
            else if (op == INSERT) {
                printf("User, enter an integer value: ");
                scanf("%d", &value);
                insert_sll(ptr, value);
                
            }
            else if (op == REVERSE) {
                printf("\nThe reversed list is\n");
                reverse_sll(ptr);
                
            }

            else if(op==QUIT){
                printf("\nThankyou!\n");
                return 0;
            }
 
            printf("\nWant to do some more operations,\nenter 1 "
                   "for TRAVERSE, 2 for INSERT , 3 for REVERSE and 4 for QUIT : ");
        }
            printf("\n\aEntered is a WRONG choice,\nenter 1 "
                   "for TRAVERSE, 2 for INSERT , 3 for REVERSE and 4 for QUIT : ");
    }
}

void insert_sll(Node **p, const int value)
{
Node* temp= (Node*)malloc(sizeof(Node));
if (temp == NULL) {
        printf("Not sufficient Memory!\n");
        exit(EXIT_FAILURE);
    }
temp->data= value;
temp->link=NULL;

Node* curr= *p;
Node* prev=NULL;

while(curr!=NULL && curr->data < value)
{
    prev=curr;
    curr=curr->link;    
}
if(prev!=NULL )
{prev->link=temp;
temp->link=curr;}

curr= *p;
if(curr!=NULL && curr->data>value)
{
    *p=temp;
    temp->link=curr;
}

if(*p==NULL)
*p=temp;

}

void traverse_sll(Node **linkp)
{
    Node *current = *linkp;
 
    /* traverse the list */
    if (current == NULL) {
        printf("\nList is EMPTY.\n");
    }
    else {
        printf("\nList contains datas : ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->link;
       }
        printf("\n");
    }
}

void reverse_sll(Node **p)
{   
    if(*p==NULL)
    printf("\nList is Empty\n");
    Node* prev = NULL;
    Node* current = *p;
    Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->link;
 
        // Reverse current node's pointer
        current->link = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *p = prev;
    traverse_sll(p);
}
    







    