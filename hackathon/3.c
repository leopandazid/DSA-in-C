/*
Perform the following operations on a singly/doubly linked list.
    a) Insert at the given position
    b) Delete alternate nodes, starting from the first node in the given list
    c) Count the number of nodes

*/

// Insert at a given position in singly linked list in C


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteAlternateNodes(struct node *head)
{
    struct node *current = head;
    struct node *next;

    while (current != NULL)
    {
        next = current->next;
        if (next == NULL)
            break;
        current->next = next->next;
        free(next);
        current = current->next;
    }
}

// Count the number of nodes in the given linked list
int count(struct node *head)
{
    int count = 0;
    struct node *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

// Insert a new node at the end of the linked list
void pushlast(struct node **head, int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    struct node *current = *head;

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}


void push(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void insertAfter(struct node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertAtPosition(struct node **head, int data, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        printf("Position not found");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;

    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);

    printf("Linked list before insertion: ");
    printList(head);

    insertAfter(head->next->next, 11);
    printf("Linked list after insertion: ");
    printList(head);

    insertAtPosition(&head, 12, 0);
    printf("Linked list after insertion: ");
    printList(head);

    insertAtPosition(&head, 13, 3);
    printf("Linked list after insertion: ");
    printList(head);

    insertAtPosition(&head, 14, 20);
    printf("Linked list after insertion: ");
    printList(head);

    return 0;
}
