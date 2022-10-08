#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t *create_queue() // return a newly created empty queue
{
	// DO NOT MODIFY!!!
	queue_t *Q = (queue_t *)malloc(sizeof(queue_t));
	Q->list = create_list();
	Q->front = Q->list->head;
	Q->rear = Q->list->tail;
	Q->size = Q->list->size;
	return Q;
}

void enqueue(queue_t *q, int data) // TODO: insert data at the end of a queue
{
	if (empty(q))
	{
		insert_back(q->list, data);
		q->front = q->rear = q->list->head;
		return;
	}
	insert_back(q->list, data);
	q->size++;
	q->rear = q->list->tail;
}

int dequeue(queue_t *q) // TODO: return the data at the front of a queue and remove it. Return -1 if queue is empty
{
	int ele;
	ele = q->list->head->data;
	if (empty(q))
	{
		return -1;
	}
	else if (q->front == q->rear)
	{
		delete_front(q->list);
		q->size--;
		q->front = q->rear = NULL;
		return ele;
	}
	q->front = q->list->head->next;
	delete_front(q->list);
	q->size--;
	q->front->prev = NULL;
	return ele;
}

int front(queue_t *q) // TODO: return the data at the front of a queue. Return -1 if queue is empty
{
	if (empty(q))
	{
		return -1;
	}
	else
	{
		return q->front->data;
	}
}

int empty(queue_t *q) // return if the queue is empty
{
	// DO NOT MODIFY!!!
	return is_empty(q->list);
}

int queue_size(queue_t *q) // returns the number of elements in the queue
{
	// DO NOT MODIFY!!!
	return q->size;
}

void delete_queue(queue_t *q) // empty the contents of the queue
{
	// DO NOT MODIFY!!!
	delete_list(q->list);
	free(q);
}
