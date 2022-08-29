typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct llist
{
	NODE *head;
}LLIST;

void initList(LLIST *pl);