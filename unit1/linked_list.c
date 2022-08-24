/*
Linked List
                    Array List                              Linked List
Random Acess         O(1)                                      O(n)
Insertion       O(n)(more copy operation)           O(1) / Random Insertion - O(n)
Deletion                same                                same as insertion

*/
#include<stdio.h>
#include<stdlib.h>
#include"sll.h"



typedef struct llist{
    Node * head;
}LList; // this stores the head pointer

void initList(Node **head){// Node* initList(Node *head){
    // **head is pointing to junk value/ any address which head pointer is pointing to
    // (*head) - pointing to address of head
    // (**head) - pointing to the address stored in head and changing that
    Node *head;
    (*head)= NULL;


    // return NULL;
    // return head;
}

int main(int argc, char const *argv[])
{
    Node *head;
    // head=initList(head); //junk value is passed which will be stored in the list 
    initList(&head); // address of the head pointer
    return 0;
}


