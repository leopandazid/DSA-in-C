#include<stdio.h>
#define MAX 50

void topDownHeap(int h[],int n);

int main()
{
	int h[MAX];
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	
	topDownHeap(h,n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",h[i]);
	}
}

void topDownHeap(int h[],int n)
{
	int c,p,key;
	
	for(int i=1;i<n;i++)
	{
		c=i;
		p=(c-1)/2;
		key=h[c]; // key gradually holds the maximum value
		printf("c=%d p=%d key=%d \n",c,p,key);
		
		while(c>0 && key>h[p])
		{
			printf("h[%d]=%d h[%d]= %d \n",c,h[c],p,h[p]);
			h[c]=h[p];
			c=p; 
			p=(c-1)/2;
			printf("c=%d and p=%d \n",c,p);
			printf("h[%d]=%d h[%d]= %d \n",c,h[c],p,h[p]);
		}
		h[c]=key; // 
		printf("c=%d and key=%d \n",c,key);
	}
}

/* 
#include<stdio.h>
#define MAX 50

void topDownHeap(int h[],int n);

int main()
{
	int h[MAX];
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	topDownHeap(h,n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",h[i]);
	}
}

void topDownHeap(int h[],int n)
{
	int c,p,key;
	
	scanf("%d",&h[0]);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&h[i]);
		c=i;
		p=(c-1)/2;
		key=h[c];
		
		while(c>0 && key>h[p])
		{
			h[c]=h[p];
			c=p;
			p=(c-1)/2;
		}
		h[c]=key;
	}
} */