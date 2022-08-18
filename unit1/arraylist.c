// Array List Implementation
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct ArrayList{
    int a[MAX];
    int last;
}list;

void newArray(list *l1){
    l1->last= -1;
}

int main(int argc, char const *argv[])
{
    // Insertion should be at end
    // as time complexity is O(1)

    // time complexity for accessing a element of the array list is also O(1)- constant time operation

    // O(n) - Linear time taking operation
    // O(n^2) - Quarditic time taking operation
    // O(2^n) - Exponential time taking operation

    // deletion is in worst case O(n)

    int a[MAX];

    return 0;
}
