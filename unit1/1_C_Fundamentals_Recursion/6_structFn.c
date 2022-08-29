#include<stdio.h>

typedef struct demo
{
	int a;
	float b;
}DEMO;

int* fn1(int a);
void fn2(int *pa,float *pb);
int fn3(int a);

int main()
{
	DEMO d1={2,2.5};
	DEMO d2=d1;
	
	printf("%d %f\n",d1.a,d2.b);
	printf("%d %f\n",d2.a,d2.b);
	
//	int *pres=fn1(d1.a);
//	printf("%d\n",*pres);

	fn2(&d1.a,&d1.b);
	printf("%d %f\n",d1.a,d1.b);
	
	//a=3
	int res=fn3(d1.a);
	printf("%d %d\n",d1.a,res);
	
}

/*
//Incorrect: Returning back address of a local variable
int* fn1(int a)
{
	a++;
	return &a;
}
*/
int fn3(int a)
{
	a++;
	return a;
}
void fn2(int *pa,float *pb)
{
	(*pa)++;
	(*pb)++;
}