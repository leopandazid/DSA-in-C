#define MAX 3

typedef struct stack{
    int s[MAX];
    int top;
}STACK;

void initStack(STACK *ps);
int isFUll(STACK *ps);
int isEmpty(STACK *ps);
void push (STACK *ps,int ele);
int pop(STACK *ps);
int StackTop(STACK *ps); // peek
void display(STACK *ps);