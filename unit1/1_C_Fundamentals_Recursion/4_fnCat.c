//Different ways of writing a function
/* 
#include<stdio.h>

int main()
{
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum=a+b;
	printf("a=%d b=%d sum=%d\n",a,b,sum);
} 
*/

#include<stdio.h>

void sum1();
void sum2(int a,int b);
int sum3();
int sum4(int a,int b);
int sum5(int *a,int *b);

int main()
{
//	sum1();
	int a,b;
	scanf("%d%d",&a,&b);
//	sum2(a,b);
//	int res=sum3();
//	int res=sum4(a,b);
//	printf("a=%d b=%d sum=%d\n",a,b,res);
	
	int res=sum5(&a,&b);
	printf("a=%d b=%d sum=%d\n",a,b,res);
}

void sum1()
{
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum=a+b;
	printf("a=%d b=%d sum=%d\n",a,b,sum);	
}

void sum2(int a,int b)
{
	int sum=a+b;
	printf("a=%d b=%d sum=%d\n",a,b,sum);
}

int sum3()
{
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum=a+b;
	printf("a=%d b=%d",a,b);
	return sum;
}

int sum4(int a,int b)
{
	a++;
	b++;
	return a+b;
}

int sum5(int *a,int *b)
{
	(*a)++;
	(*b)++;
	return *a + *b;
}