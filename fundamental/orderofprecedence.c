/*
order of precedence 

1. Post increment / decrement - L to R - use and then change -- executed first but not incremented
2. Pre increment/decrement - R to L - change and then use - it is faster
3. derefrencing operator- R to L
pre increment and derefrencing operator have same precedence

*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a[]= {10,20,30,40,50,60,70};
    int *ptr =a;
    printf("%d %d %d \n",a[0],a[1],a[2]);
    printf("%d %d %d \n",*(ptr+0), *(ptr+1),*(ptr+2));

    int b= *ptr++;
    printf("%d %d \n",b,*ptr);

    int c= *(++ptr); // works like ptr=ptr+1; and then c= *ptr;
    printf("%d %d \n",c,*(ptr));

    int e= *++ptr; // works like ptr=ptr+1; and then c= *ptr;
    printf("%d %d \n",e,*ptr);

    int d= *(ptr++); // works like d= *ptr; and then ptr= ptr+1;
    printf("%d %d \n",d,*(ptr));

    ptr=a;
    int f= ++*ptr; // first pointer is derefrenced and then increment the memory location of the ptr
    printf("%d %d \n",e,*ptr); // 11 11
    // *ptr= *ptr+1;
    // e= *ptr;
    // this is not valid
    // printf("%d \n",++10);

    int x=20;
    int *ptr2 = &x;
    // printf("%d %d\n",x, *(ptr2+1) ); // creates a dangling pointer
    // segmentation fault 

    return 0;
}
