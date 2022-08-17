// Different ways of writing a func

#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a,b,sum;
    scanf("%d %d",&a,&b);
    sum = a+b;
    printf("%d \n",sum);
    return 0;
}

int sum1(int *a,int *b){ // pass by reference
    *a++;
    *b++;
    return *a+*b;
}

int sum1(int a,int b){ // pass by value
    a++;
    b++;
    return a+b;
}