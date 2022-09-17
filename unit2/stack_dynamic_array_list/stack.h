typedef struct stack{
    int *s; 
    int top;
    int size; // no of elements in the stack
    // size of the array
}STACK;

void initStack(STACK *ps,int n);
int isFUll(STACK *ps);
int isEmpty(STACK *ps);
void stackDouble(STACK *ps);
void push (STACK *ps,int ele);
int pop(STACK *ps);
int StackTop(STACK *ps); // peek
void display(STACK *ps);
void destroyStack(STACK *ps);