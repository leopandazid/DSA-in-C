// Array List Implementation
#include<stdio.h>
#include<stdlib.h>
#include"arraylist.h"

void initList(list *ptr){
    ptr->last=-1;
}

int append(list *ptr,int ele){
    if (ptr->last == MAX-1 ) {
        return 0;
    }
    else{
        ptr->last++;
        ptr->a[ptr->last]= ele;
        return 1;
    }

}
int deleteLast(list *ptr,int *ele){
    if (ptr->last ==-1 ){
        return 0;
    }
    else{
        *ele = ptr->a[ptr->last];
        ptr->last--;
        return 1;
    }
}
void display(list *ptr){
    if (ptr->last==-1){
        printf("List is empty");
    }
    else{
        for(int i=0; i<= ptr->last;i++){
            printf("%d\t",ptr->a[i]);
        }
    }
}