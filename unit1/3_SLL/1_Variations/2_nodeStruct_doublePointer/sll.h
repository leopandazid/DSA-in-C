typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initList(NODE** phead);