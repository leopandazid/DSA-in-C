#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

void initStack(STACK *ps){
    ps->top=-1;
}

int isFUll(STACK *ps){
    return (ps->top==MAX-1);
}

int isEmpty(STACK *ps){
    return ps->top==-1;
}

void push (STACK *ps,int ele){
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
