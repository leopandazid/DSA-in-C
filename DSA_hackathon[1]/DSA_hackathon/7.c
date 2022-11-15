/*
7) Perform the following operations on a binary tree.
    a) Compute the height
    b) Count the no. of nodes   
*/

#include <stdio.h>
#include <stdlib.h>
  
// Structure of a Tree Node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;
  
// Helper function to allocate a new node
// with the given data
node* newNode(int data)
{
  node * Node = (node *)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
  
// Function to get the left height of
// the binary tree
int left_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->left;
    }
    // Return the left height obtained
    return ht;
}
  
// Function to get the right height
// of the binary tree
int right_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->right;
    }
  
    // Return the right height obtained
    return ht;
}
  
// Function to get the count of nodes
// in complete binary tree
int TotalNodes(node* root)
{
    // Base Case
    if (root == NULL)
        return 0;
    // Find the left height and the
    // right heights
    int lh = left_height(root);
    int rh = right_height(root);
    // If left and right heights are
    // equal return 2^height(1<<height) -1
    if (lh == rh)
        return (1 << lh) - 1;
    // Otherwise, recursive call
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}
  
// Driver Code
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->right = newNode(8);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);
    printf("%d",TotalNodes(root));
    return 0;
}