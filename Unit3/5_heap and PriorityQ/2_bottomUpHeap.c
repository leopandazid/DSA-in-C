#include<stdio.h>
#define MAX 50

void bottomUpHeap(int h[],int n);

int main()
{
	int h[MAX];
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	
	bottomUpHeap(h,n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",h[i]);
	}
}

void bottomUpHeap(int h[],int n)
{
	int c,p,key;
	
	for(int i=n/2-1;i>=0;i--)
	{
		p=i;
		c=2*p+1;
		key=h[p];
		
		while(c<n)
		{
			if(c+1 < n)
			{
				if(h[c+1]>h[c])
					c=c+1;
			}
			if(key < h[c])
			{
				h[p]=h[c];
				p=c;
				c=2*p+1;
			}
			else
				break;
		}
		h[p]=key;
	}
}