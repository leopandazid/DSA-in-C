#include<stdio.h>
#include<stdlib.h>
#include"arraylist.h"

int main(){
    
    // Insertion should be at end
    // as time complexity is O(1)

    // time complexity for accessing a element of the array list is also O(1)- constant time operation

    // O(n) - Linear time taking operation
    // O(n^2) - Quarditic time taking operation
    // O(2^n) - Exponential time taking operation

    // deletion is in worst case O(n)

    list alst;
    initList(&alst);
    int choice=0;
    int ele;
    int status;

    do{
        printf("1. Append \n2. Delete Last \n3. Display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            scanf("%d",&ele);
            status = append(&alst, ele);
            if(status ){
                printf("Inserted %d successfully",ele);
            }
            else{
                printf("List is full");
            }
            break;
        case 2:
            // scanf("%d",&ele);
            status = deleteLast(&alst, &ele);
            if(status ){
                printf("Deleted %d successfully",ele);
            }
            else{
                printf("List is empty");
            }        
            break;
        case 3:
            display(&alst);
        
        default:
            break;
        }
        

    }while (choice<3);

}