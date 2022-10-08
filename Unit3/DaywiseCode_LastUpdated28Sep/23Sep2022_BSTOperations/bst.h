typedef struct node
{
	int info;
	struct node *left;
	struct node *right;
}NODE;

typedef struct TREE
{
	NODE *root;
}TREE;

void initTree(TREE *pt);
void insertNode(TREE *pt,int ele);
void preorderTraversal(TREE *pt);
void inorderTraversal(TREE *pt);
void postorderTraversal(TREE *pt);
void destroyTree(TREE *pt);
NODE* search(TREE *pt,int ele);
void insertRec(TREE *pt,int ele);
NODE* searchWrapper(TREE *pt,int ele);