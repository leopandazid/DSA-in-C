#define MAX 3

typedef struct stack
{
	int s[MAX];
	int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps,int ele);
int pop(STACK *ps);
int stackTop(STACK *ps);		//Peek
void display(STACK *ps);