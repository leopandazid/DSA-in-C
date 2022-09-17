#define MAX 3
typedef struct queue
{
	int data;
	int priority;
}QUEUE;

void enqueue(QUEUE pq[],int info,int pri,int *count);
QUEUE dequeue(QUEUE pq[],int *count);
void display(QUEUE pq[],int *count);

