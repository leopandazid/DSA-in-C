typedef struct node
{
	int data;
	struct node *next;
}NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq,int ele);
int dequeue(QUEUE *pq,int *pele);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);
