// Implement Josephus problem using circular linked list in C


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    struct node *new_node, *temp;
    int i;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = head;
    temp = head;
    for (i = 2; i <= n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = head;
        temp->next = new_node;
        temp = temp->next;
    }
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}

void josephus(int k)
{
    struct node *p, *q;
    int i;
    p = head;
    q = head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d ", p->data);
        free(p);
        p = q->next;
    }
    printf("%d ", p->data);
    free(p);
}

int main()
{
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    create(n);
    printf("The people standing in the circle are: ");
    display();
    printf("\nThe people eliminated in the order are: ");
    josephus(k);
    return 0;
}

