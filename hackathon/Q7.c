/* 7) Perform the following operations on a binary tree.

    a) Compute the height

    b) Count the no. of nodes
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

//a)
int Height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lh = Height(node->left);
        int rh = Height(node->right);
  
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}

//b)
int left_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->left;
    }
    return ht;
}

int right_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->right;
    }
    return ht;
}

int TotalNodes(node* root)
{
    if (root == NULL)
        return 0;
    int lh = left_height(root);
    int rh = right_height(root);
    if (lh == rh)
        return (1 << lh) - 1;
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}