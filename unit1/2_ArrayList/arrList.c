#include<stdio.h>
#include"arrList.h"

int main()
{
	ARLST alst;
	
	initList(&alst);
	
	int choice;
	int ele;
	int status;
	
	do{
		printf("1.Append 2.Delete Last 3.Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("Enter an integer\n");
					scanf("%d",&ele);
					status=append(&alst,ele);
					if(status)
						printf("Inserted %d successfully\n",ele);
					else
						printf("List is already full\n");
					break;
					
			case 2: status=deleteLast(&alst,&ele);
					if(status)
						printf("Deleted %d successfully\n",ele);
					else
						printf("List is already empty\n");
					break;
			case 3:display(&alst);
					break;
		}
	}while(choice<4);
}


