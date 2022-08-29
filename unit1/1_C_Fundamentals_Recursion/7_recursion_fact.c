#include<stdio.h>
unsigned int factorial(unsigned int n);

int main()
{
	unsigned int n;
	
//	printf("%lu\n",sizeof(long int));
	printf("Enter a positive integer\n");
	scanf("%u",&n);
	
	unsigned int res=factorial(n);
	printf("%u\n",res);
}

unsigned int factorial(unsigned int n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}