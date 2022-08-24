// self refrential structure
typedef struct node
{
    /* data */
    int data;
    Node *next;
}Node;

void initList(Node **head);
Node* initList1(Node *phead);
void initList2(Node **head);