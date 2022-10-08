/*
Postorder: Left Right Root

We have discussed iterative inorder and iterative preorder traversals. In this post, 
iterative postorder traversal is discussed, which is more complex than the other two 
traversals (due to its nature of non-tail recursion, there is an extra statement after the 
final recursive call to itself). Postorder traversal can easily be done using two stacks, though. 
The idea is to push reverse postorder traversal to a stack. Once we have the reversed postorder 
traversal in a stack, we can just pop all items one by one from the stack and print them; this 
order of printing will be in postorder because of the LIFO property of stacks. Now the question 
is, how to get reversed postorder elements in a stack – the second stack is used for this purpose. 
For example, in the following tree, we need to get 1, 3, 7, 6, 2, 5, 4 in a stack. If take a closer 
look at this sequence, we can observe that this sequence is very similar to the preorder traversal. 
The only difference is that the right child is visited before left child, and therefore the sequence 
is “root right left” instead of “root left right”. So, we can do something like iterative preorder 
traversal with the following differences: 

a) Instead of printing an item, we push it to a stack. 
b) We push the left subtree before the right subtree.
Following is the complete algorithm. After step 2, we get the reverse of a postorder traversal in the second stack. 
We use the first stack to get the correct order. 
 

1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack
Let us consider the following tree 
 



Following are the steps to print postorder traversal of the above tree using two stacks.

1. Push 1 to first stack.
      First stack: 1
      Second stack: Empty

2. Pop 1 from first stack and push it to second stack. 
   Push left and right children of 1 to first stack
      First stack: 2, 3
      Second stack: 1

3. Pop 3 from first stack and push it to second stack. 
   Push left and right children of 3 to first stack
      First stack: 2, 6, 7
      Second stack: 1, 3

4. Pop 7 from first stack and push it to second stack.
      First stack: 2, 6
      Second stack: 1, 3, 7

5. Pop 6 from first stack and push it to second stack.
      First stack: 2
      Second stack: 1, 3, 7, 6

6. Pop 2 from first stack and push it to second stack. 
   Push left and right children of 2 to first stack
      First stack: 4, 5
      Second stack: 1, 3, 7, 6, 2

7. Pop 5 from first stack and push it to second stack.
      First stack: 4
      Second stack: 1, 3, 7, 6, 2, 5

8. Pop 4 from first stack and push it to second stack.
      First stack: Empty
      Second stack: 1, 3, 7, 6, 2, 5, 4

The algorithm stops here since there are no more items in the first stack. 
Observe that the contents of second stack are in postorder fashion. Print them. 
*/

#include <stdio.h>
#include <stdlib.h>

// Maximum stack size
#define MAX_SIZE 100

// A tree node
struct Node {
	int data;
	struct Node *left, *right;
};

// Stack type
struct Stack {
	int size;
	int top;
	struct Node** array;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (struct Node**)malloc(stack->size * sizeof(struct Node*));
	return stack;
}

// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{
	return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return NULL;
	return stack->array[stack->top--];
}

// An iterative function to do post order traversal of a given binary tree
void postOrderIterative(struct Node* root)
{
	if (root == NULL)
		return;

	// Create two stacks
	struct Stack* s1 = createStack(MAX_SIZE);
	struct Stack* s2 = createStack(MAX_SIZE);

	// push root to first stack
	push(s1, root);
	struct Node* node;

	// Run while first stack is not empty
	while (!isEmpty(s1)) {
		// Pop an item from s1 and push it to s2
		node = pop(s1);
		push(s2, node);

		// Push left and right children of removed item to s1
		if (node->left)
			push(s1, node->left);
		if (node->right)
			push(s1, node->right);
	}

	// Print all elements of second stack
	while (!isEmpty(s2)) {
		node = pop(s2);
		printf("%d ", node->data);
	}
}

// Driver program to test above functions
int main()
{
	// Let us construct the tree shown in above figure
	struct Node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	postOrderIterative(root);

	return 0;
}
