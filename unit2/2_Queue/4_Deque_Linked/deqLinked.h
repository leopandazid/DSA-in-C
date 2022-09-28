// double ended queue

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}NODE;


typedef struct queue
{
	NODE *front;
	NODE *rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueueFront(QUEUE *pq,int ele);
void enqueueRear(QUEUE *pq,int ele);
int dequeueFront(QUEUE *pq,int *pele);
int dequeueRear(QUEUE *pq,int *pele);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);