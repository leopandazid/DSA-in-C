#include<stdio.h>
#include"bst.h"

int main()
{
	TREE tobj;
	
	initTree(&tobj);
	int choice,ele;
	NODE* res;
	printf("1.Insert Node 2.Inorder 3. Preorder 4.Postorder ");
	printf("5.InsertNodeRec 6.Search 7.searchRec\n");
	scanf("%d",&choice);
	do
	{		
		switch(choice)
		{
			case 1: printf("Enter an integer\n");
					scanf("%d",&ele);
					insertNode(&tobj,ele);
					break;
			case 2:inorderTraversal(&tobj);
					break;
			case 3:preorderTraversal(&tobj);
					break;
			case 4:postorderTraversal(&tobj);
					break;
					
			case 5:printf("Enter an integer\n");
					scanf("%d",&ele);
					insertRec(&tobj,ele);
					break;
			case 6:printf("Enter an integer\n");
					scanf("%d",&ele);
					res=search(&tobj,ele);
					if(res==NULL)
						printf("%d not found\n",ele);
					else
						printf("%d found\n",res->info);
					break;
			case 7:printf("Enter an integer\n");
					scanf("%d",&ele);
					res=searchWrapper(&tobj,ele);
					if(res==NULL)
						printf("%d not found\n",ele);
					else
						printf("%d found\n",res->info);
					
					break;
		}
		printf("1.Insert Node 2.Inorder 3. Preorder 4.Postorder\n");
		printf("5.InsertNodeRec 6.Search 7.SearchRec\n");
		scanf("%d",&choice);
	}while(choice<8);
	destroyTree(&tobj);
}