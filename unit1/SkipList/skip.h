typedef struct node {
    int data;
    struct node *next;
}Node;

typedef struct list{
    Node *head;
    int length;
};


// O(1) if size is stored explicitly, else O(n)
// int size(list *pl);
// O(1)
// int isEmpty(list *pl);
// O(n)
// int FindElement(list *pl,int k);
// O(1) - assuming item already found 
// void Insert(list *pl);

// Skip List supports O(log(n)) - search and insertion complexity 
// elements are arranged in non decreasing sequence

// a probabilistic alternative to balanced trees
// Balanced trees have time complexity of O(log n)

// Binary Search has timecomplexity as log n to the base 2 as we divide the array to 1/2 each time
// it would be base 3 if we would have divide the array to 1/3 each time and so on
// Since the value of n is very large we do not care for the additive constants and 
// so we represent it as log n to the base e


// A perfect skip List
// - have log n to base 2 levels
// 

// The skip list is solid and trustworthy.
// To add a new node to it, it will be inserted extremely quickly. 
// Easy to implement compared to the hash table and binary search tree
// The number of nodes in the skip list increases, and the possibility of the worst-case decreases
// Requires only Θ(logn) time in the average case for all operations.
// Finding a node in the list is relatively straightforward.

// Disadvantages of Skip List:

// It needs a greater amount of memory than the balanced tree.
// Reverse search is not permitted.
// Searching is slower than a linked list
// Skip lists are not cache-friendly because they don’t optimize the locality of reference


