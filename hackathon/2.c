// Reverse the given singly linked list in C


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void reverse() {
    struct node *current = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void print() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n"); 
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    reverse();
    print();
    return 0;
}


