#include<stdio.h>

int main()
{
	int a=10;
	int *ptri=&a;
		
	printf("%d %d\n",a,*ptri);
	
	int **ptrp=&ptri;
	printf("%d\n",**ptrp);
	
	float b=2.5;
	float *ptrf=&b;
	
	printf("%f\n",*ptrf);
}