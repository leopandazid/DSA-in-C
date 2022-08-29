//pointers and constant

#include<stdio.h>

int main()
{
	const int a=10;	//int const a=10;
//	a=10;	//Error
//	a=a+1;	//Error
	printf("%d\n",a);
	
	int *ptr=&a;
	(*ptr)++;	//Warning
	printf("%d %d\n",a,*ptr);
	
	const int *ptr1=&a;	//int const *ptr1=&a;
	printf("%d %d\n",a,*ptr1);
//	(*ptr1)++;	//Error

	int b=20;
	ptr=&b;
	printf("%d %d\n",b,*ptr);
	
	int *const ptr2=&b;
	printf("%d %d\n",b,*ptr2);
	++*ptr2;
	printf("%d %d\n",b,*ptr2);
	
	int c=100;
//	ptr2=&c;	//Error

	const int* const ptr3=&a;
//	++*ptr3;	//Error
//	ptr3=ptr2;	//Error
}

int const *ptr;		//ptr is pointing to const int
const int *ptr;		//ptr is pointing to const int
int *const ptr;		//ptr is a const pointer to an int
int const *const ptr; //ptr is a const pointer to a const int
const int *const ptr; //ptr is a const pointer to a const int