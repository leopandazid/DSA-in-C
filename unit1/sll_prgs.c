
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;


// Function to Concat a linked list 2 at end of list 1
// Time Complexity - O(n)
void concat (Node **head1, Node **head2){
    Node *temp=(*head1);
    if ((*head1)==NULL){
        (*head1) = (*head2);
        return;
    }
    else if (*head2==NULL){
        return;
    }
    while (temp->next!=NULL){
        temp=temp->next; // get the last node
    }
    temp->next = *head2; 

}

/* Function to reverse the linked list 
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/
void reverse(Node *head)
{
    // Initialize current, previous and next pointers
    Node* current = head;
    Node *prev = NULL, *next = NULL;
 
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}


/*
Recursive Method: 

   1) Divide the list in two parts - first node and 
      rest of the linked list.
   2) Call reverse for the rest of the linked list.
   3) Link rest to first.
   4) Fix head pointer

Time Complexity: O(n) 
Auxiliary Space: O(n)
*/
Node* reversel(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
 
    /* reverse the rest list and put
      the first element at the end */
    Node* rest = reversel(head->next);
    head->next->next = head;
 
    /* tricky step -- see the diagram */
    head->next = NULL;
 
    /* fix the head pointer */
    return rest;
}


/*Search for a node*/
// linear search 
int search (int value, Node *head){
    while (head!=NULL){
        if (value==head->data)
            return 1;
        head=head->next;
    }
    return 0;
}

/*
Create an ordered linked list
and write the insert function (ascending order)
*/