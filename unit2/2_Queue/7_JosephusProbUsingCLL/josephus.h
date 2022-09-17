typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct list
{
	NODE *head,*tail;
}LIST;

void initList(LIST *pl);
void createList(LIST *pl);
void display(LIST *pl);
int winner(LIST *pl,int start,int skip);