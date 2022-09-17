typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct stack
{
	NODE *top;
}STACK;

void initStack(STACK *ps);
void push(STACK *ps,int ele);
void display(STACK *ps);
void destroyStack(STACK *ps);
/*precondition: List is not empty,
deleted ele info is returned back*/
int pop(STACK *ps);
//List is created and may be empty or may have node(s)
int stackTop(STACK *ps);
int isEmpty(STACK *ps);
