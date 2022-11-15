// Create a Binary search tree using implicit array representation and do the preorder, inorder, and postorder 
// traversal on the same.


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int tree[MAX];
int root = 0;

void insert(int data)
{
    int i = 0;
    while (tree[i] != 0)
    {
        if (data < tree[i])
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
    tree[i] = data;
}

void preorder(int i)
{
    if (tree[i] != 0)
    {
        printf("%d ", tree[i]);
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }
}

void inorder(int i)
{
    if (tree[i] != 0)
    {
        inorder(2 * i + 1);
        printf("%d ", tree[i]);
        inorder(2 * i + 2);
    }
}


void postorder(int i)
{
    if (tree[i] != 0)
    {
        postorder(2 * i + 1);
        postorder(2 * i + 2);
        printf("%d ", tree[i]);
    }
}

int main()
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(data);
    }
    printf("Preorder traversal: ");
    preorder(root);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    return 0;
}

