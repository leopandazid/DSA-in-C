//structures and functions

typedef struct student
{
	int rNo;
	char name[20];
}STUDENT;

//STUDENT a;
//STUDENT *ptr=&a;		//ptr->rNo OR (*ptr).rNo

void readData(int n,STUDENT s[]);
void printData(int n,STUDENT *s);
#include<stdio.h>

int main()
{
	STUDENT s[60];
	
	int n;
	printf("Enter the number of students\n");
	scanf("%d",&n);
	printf("Enter %d stud rNo and name\n",n);
	readData(n,s);
	printData(n,s);
}

void readData(int n,STUDENT *s)	//void readData(int n,STUDENT s[])
{
	for(int i=0;i<n;i++)
		scanf("%d %s",&s[i].rNo,s[i].name);
}
void printData(int n,STUDENT *s)
{
	for(int i=0;i<n;i++)
		printf("%d %s\n",s[i].rNo,s[i].name);	
}