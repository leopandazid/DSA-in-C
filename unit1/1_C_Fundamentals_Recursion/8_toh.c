#include<stdio.h>

void ToH(int n,char src,char aux,char dest);

int main()
{
	int n;
	scanf("%d",&n);
	
	ToH(n,'A','B','C');
}

void ToH(int n,char src,char aux,char dest)
{
	if(n==1)
		printf("Move disk %d from %c to %c\n",n,src,dest);
	else
	{
		ToH(n-1,src,dest,aux);
		printf("Move disk %d from %c to %c\n",n,src,dest);
		ToH(n-1,aux,src,dest); // tail recursion
	}
}