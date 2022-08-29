#include<stdio.h>

/*
order of precedence 

1. Post increment / decrement - L to R - use and then change -- executed first but not incremented
2. Pre increment/decrement - R to L - change and then use - it is faster
3. derefrencing operator- R to L
pre increment and derefrencing operator have same precedence

*/

int main()
{
	int a[]={10,20,30};
	
	int *ptr=a;
	printf("%d %d %d\n",a[0],a[1],a[2]);
	printf("%d %d %d\n",*(ptr+0),*(ptr+1),*(ptr+2));
	
	int b=*ptr++;
	printf("%d %d\n",b,*ptr);
	
	ptr=a;
	int c=*(ptr++);
	printf("%d %d\n",c,*ptr);
	
	ptr=a;
	int d=*++ptr;
	printf("%d %d\n",d,*ptr);
	
	ptr=a;
	int e=++*ptr;
	printf("%d %d\n",e,*ptr);
	
	int x=20;
	int *ptr1=&x;
//	printf("%d %d\n",x,*(ptr1+1)); //Location ptr1+1 is not reserved by us
	
}