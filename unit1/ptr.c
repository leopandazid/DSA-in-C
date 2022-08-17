#include<stdio.h>

int main(){
    int a=10;
    int *ptri= &a;
    printf("%d \n%d\n",a,*ptri); //10 10
    int **ptrp = &ptri;
    printf("%d\n",**ptrp); //10
    int ***ptr3= &ptrp;
    printf("%d\n",***ptr3); //10

    float b=2;
    ptri=&b; // leads to undefined behaviour 
    printf("%f\n",*ptri);

    float *ptrf= &b;
    printf("%f\n",*ptrf);


    return 0;
}