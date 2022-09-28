#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 20


typedef struct {
    int stack1[MAXSIZE];    // stack used for enqueue
    int stack2[MAXSIZE];    // stack used for dequeue
    int top1;               // top element position of stack1
    int top2;               // top element position of stack2
} MyQueue;

// checks if stack is full or not
int isFull(MyQueue *q){
    return q->top1== MAXSIZE-1;
}

// check if the queue is empty
bool empty(MyQueue *q) {
    return q->top1<0;
}

bool emptys2(MyQueue *q){
    return q->top2<0;
}

// copies the element from stack1 to stack2
void copytoStack2(MyQueue *q){
    if (empty(q)){
        q->top1=-1;
        q->top2=-1;
        return;
    }
    int j=0;
    for (int i =q->top1; i>=0;i--){
        q->stack2[j] =q->stack1[i];
        j++;
    }
    q->top2=j-1;
    q->top1=-1;
}

// copies the element from stack2 to stack1
void copytoStack1(MyQueue *q){
    if (emptys2(q)){
        q->top1=-1;
        q->top2=-1;
        return;
    }
    int j=0;
    for (int i =q->top2; i>=0;i--){
        q->stack1[j] =q->stack2[i];
        j++;
    }
    q->top1=j-1;
    q->top2=-1;
}

// push the element x to the rear end of the queue
void enqueue(MyQueue *q, int x) {
    if (!isFull(q)){
        q->stack1[++q->top1]= x;
    }
}


// retrieve and remove the element from the front end of the queue
int dequeue(MyQueue *q) {
    if(empty(q)){
        return -1;
    }
    
    copytoStack2(q);
    int k= q->stack2[q->top2];
    q->top2--;
    copytoStack1(q);
    return k;
    
    
}


// retrieve the element from the front end of the queue
int peek(MyQueue *q) {
    if (empty(q)){
        return -1;
    }
    copytoStack2(q);
    int k= q->stack2[q->top2];
    copytoStack1(q);
    return k;
}


int validate(MyQueue *q, int pops){
    if(q->top2 != -1 || q->top1 < pops){
        return -1;
    }

    int x = pops, ele = -1;
    while(x > 0 && q->top1 != -1){
        q->stack2[++q->top2] = q->stack1[q->top1--];
        x--;
    }

    if(q->top1 != -1){
        ele = q->stack1[q->top1];
    }

    x = pops;
    while(x > 0 && q->top2 != -1){
        q->stack1[++q->top1] = q->stack2[q->top2--];
        x--;
    }

    return ele;
}


int main(){
    MyQueue q;
    q.top1 = -1;
    q.top2 = -1;

    int no_of_operations;
    scanf("%d", &no_of_operations);

    int ele, correct_ele, no_of_pops;
    char operation;

    for(int i = 0; i < no_of_operations; i++){
        scanf(" %c", &operation);
        switch (operation)
        {   
            case 'E':
                scanf("%d", &ele);
                enqueue(&q, ele);
                printf("1 ");
                break;
            
            case 'D':
                ele = dequeue(&q);
                printf("%d ", ele);

                break;
            
            case 'P':
                ele = peek(&q);
                printf("%d ", ele);
                break;

            case 'V':
                scanf("%d", &no_of_pops);
                printf("%d ", validate(&q, no_of_pops));
                break;
        }
    }

    return 0;
}