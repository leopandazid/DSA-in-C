#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

void initStack(STACK *ps,int n){

    ps->size=n; // what should be the size of the array
    // n cannot be zero
    ps->top=-1;
    ps->s = malloc(sizeof(int)*n); // allocation of the memory is done here for the dynamic array
}

int isFUll(STACK *ps){
    return ps->top == ps->size-1;
}

int isEmpty(STACK *ps){
    return ps->top==-1;
}

// doubles the size by 2 to avoid stack overflow
void stackDouble(STACK *ps){ 
    ps->size=2*ps->size;
    ps->s=realloc(ps->s,ps->size*sizeof(int)); // reallocating memory
}

void push (STACK *ps,int ele){
    if(isFUll){
        // stack overflow will not occur due to this 
        stackDouble(ps);
    }
    ps->top++;
    ps->s[ps->top]=ele;
    // ps->s[++ ps->top]=ele
}

int pop(STACK *ps){
    int popEle= ps->s[ps->top--];
    return popEle;
    // return ps->s[ps->top--];
}

int StackTop(STACK *ps){ // peek
    return ps->s[ps->top];
}

void display(STACK *ps){
    if (ps->top==-1)
        printf("Stack is Empty");
    else{
        for (int i=ps->top;i>=0;i--){
            printf("%d\t", ps->s[i]);
        }
    }
}
void destroyStack(STACK *ps){
    free(ps->s);
    // not necessary
    ps->s=NULL; // safe ptr
    ps->top= -1;
    ps->size=0;
}

