typedef struct node {
    int data;
    struct node *next;
}Node;

void deleteAlt(Node **head);
void initList(Node **head);
// Function to push node at the head
void push (Node **head,int data); 
void destroyList(Node **head);
void display(Node *head);