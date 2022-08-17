// pointer and constants

#include<stdio.h>
int main(int argc, char const *argv[])
{
    const int a=10;
    // a=10;
    // this will create an error
    // we are making changes to a read only variable
    // a+=1;
    printf("%d\n",a);

    int *ptr= &a;
    int b= *ptr+1;
    printf("%d %d %d\n", a,*ptr,b);

    int *ptr1= &a; // its a pointer pointing to an integer and not const pointer
    (*ptr1)++; // this is the way to change the const value of a variable
    // gives a warning
    printf("%d %d\n",a,*ptr); 

    const int *ptr2 =&a;
    // (*ptr2)++; //increment of read-only location '*ptr2'
    // now we cannot change this value now because of const pointer
    printf("%d %d\n",a,*ptr2);

    int b=20;
    ptr= &b;
    printf("%d %d\n",b,*ptr); 

    // declaring the constant pointer
    int * const ptrc=&a;; // precedence is R to L
    printf("%d %d\n",a,*ptrc); 
    ++*ptrc;
    printf("%d %d\n",a,*ptrc); 

    int c=100;
    // ptrc=&c; // assignment to read only region

    // create a constant pointer to a constant variable
    const int* const ptr3 =&a;
    // invalid operations
    // ++*ptr3;
    // ptr3= ptr2;


    /*
    int const *ptr; // ptr is pointing to const int
    const int *ptr; // ptr is pointing to const int
    int *const ptr; // ptr is a const pointer to an int
    int const *const ptr; // ptr is a const pointer to a constant int
    const int *const ptr; // ptr is a const pointer to a constant int
    */



    return 0;
}
