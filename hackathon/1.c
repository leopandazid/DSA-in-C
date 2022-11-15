//  Create an ordered singly linked list in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    struct node *current = head;
    struct node *previous = NULL;

    while (current != NULL && current->data < data)
    {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        previous->next = new_node;
        new_node->next = current;
    }
}

void print()
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    insert(5);
    insert(3);
    insert(1);
    insert(4);
    insert(2);

    print();

    return 0;
}
