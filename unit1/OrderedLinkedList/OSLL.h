typedef struct node {
    int data;
    struct node *next;
}Node;

/* Time Complexity - O(1)- it represents upper bound of time complexity 
We use theta to represent the exact bound - theta(1)
For eg - to find length of linked list, it will have exact bound of theta (n)
*/
void initList(Node **head);
void insert(Node **head,int ele);
void delete(Node **head,int ele);
void merge(Node **head1,Node **head2); // returns head1 as modified merged list

