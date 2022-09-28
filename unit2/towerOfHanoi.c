/*
Tower of Hanoi Problem

Disk movements - 2^n -1 

Have exponential growing functions

Varanasi Problem 

*/

#include<stdio.h>
// tower of Hanoi
void TOH(int n, char src,char aux,char dest){ // trace for n=3
    if(n==1){
        printf("Move %d from %c to %c", n, src, dest);
    }
    else {
        TOH(n-1, src, dest,aux); // sending disks to aux peg
        printf("Move %d from %c to %c", n, src, dest);
        TOH (n-1, aux,src,dest);
        printf("Move %d from %c to %c", n, src, dest);

    }

}


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);

    TOH(n,'A','B','C');
    return 0;
}


