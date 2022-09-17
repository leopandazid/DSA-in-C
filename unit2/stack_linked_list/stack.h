typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct STACK
{
	NODE *head;
}STACK;

void initList(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps,int ele);
void display(STACK *ps);
int pop(STACK *ps);
void destroyList(STACK *ps);
int stackTop(STACK *ps);