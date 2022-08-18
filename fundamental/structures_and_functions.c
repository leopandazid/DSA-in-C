// structures and functions

#include <stdio.h>

typedef struct student{
    int rollNo;
    char name[20];
}s;

void readData(int n,s *arr){
    // void readData(int n,s *arr)
    printf("%lu\n", sizeof(arr)); // it returns the size of the pointer
    // array gets degenerated to a pointer when passed to a function
    for (int i=0; i<n;i++){
        scanf("%d %s", &arr[i].rollNo, arr[i].name);
    }
}

void printData(int n, s *arr){
    for (int i=0; i<n;i++){
        printf("%d %s\n", arr[i].rollNo, arr[i].name);
    }
    // never return the address of a local variable
    // If we try to derefrence it, then we might get junk values or the program might crash 
}

int main(int argc, char const *argv[])
{
    s a= {23, "Shreya"};
    s *ptr = &a;

    printf("%d",ptr->rollNo);
    printf("%d",(*ptr).rollNo);

    s arr[60];
    printf("%lu\n", sizeof(arr)); // it returns the size of the array
    int n;
    printf("Enter the number of students\n");
    scanf("%d",&n);
    readData(n,arr);


    return 0;
}
