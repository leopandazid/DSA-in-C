#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

list_t *create_list() // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t *l = (list_t *)malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t *list, int data) // TODO: inserts data to the beginning of the linked list
{
	node_t *temp;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if (temp == NULL)
	{
		return;
	}
	if (list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	else
	{
		list->head->prev = temp;
		temp->next = list->head;
		list->head = temp;
	}
	list->size++;
}

void insert_back(list_t *list, int data) // TODO: inserts data to the end of the linked list
{
	node_t *temp;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if (temp == NULL)
	{
		return;
	}
	if (list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	else
	{
		list->tail->next = temp;
		temp->prev = list->tail;
		list->tail = temp;
	}
	list->size++;
}

void insert_after(list_t *list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t *p;
	node_t *temp;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if (temp == NULL)
	{
		return;
	}
	p = list->head;
	while (p != NULL && p->data != prev)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return;
	}
	else if (p == list->tail)
	{
		insert_back(list, data);
		return;
	}
	temp->prev = p;
	temp->next = p->next;
	if (p->next != NULL)
	{
		p->next->prev = temp;
	}
	p->next = temp;
	list->size++;
}

void delete_front(list_t *list) // TODO: delete the start node from the linked list.
{
	node_t *p;
	if (list->head == NULL)
	{
		return;
	}
	p = list->head;
	list->head = list->head->next;
	if (list->head != NULL)
	{
		list->head->prev = NULL;
	}
	free(p);
	list->size--;
	return;
}

void delete_back(list_t *list) // TODO: delete the end node from the linked list.
{
	node_t *p;
	if (list->head == NULL)
	{
		return;
	}
	p = list->tail;
	if (list->tail->prev == NULL)
	{
		list->head = NULL;
		list->tail = NULL;
		free(p);
		list->size--;
		return;
	}
	else
	{
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
		free(p);
		list->size--;
		return;
	}
}

void delete_node(list_t *list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t *p;
	int count = 0;
	if (list->head == NULL)
	{
		return;
	}
	p = list->head;
	if (p->data == data)
	{
		list->head = p->next;
		if (list->head != NULL)
		{
			list->head->prev = NULL;
		}
		free(p);
		list->size--;
		return;
	}
	while (p != NULL && p->data != data)
	{
		count++;
		p = p->next;
	}
	if (p == NULL)
	{
		return;
	}
	else if (p == list->tail)
	{
		delete_back(list);
		return;
	}
	p->prev->next = p->next;
	if (p->next != NULL)
	{
		p->next->prev = p->prev;
	}
	free(p);
	list->size--;
	return;
}

node_t *search(list_t *list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
	node_t *p;
	int flag;
	p = list->head;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		while (p != NULL)
		{
			if (p->data == data)
			{
				return p;
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 1)
		{
			return NULL;
		}
	}
}

int is_empty(list_t *list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t *list) // returns the number of nodes in the linked list.
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t *head) // helper
{
	// DO NOT MODIFY!!!
	if (head == NULL)
		return;
	delete_nodes(head->next);
	free(head);
}

void delete_list(list_t *list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t *list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t *it = list->head;
	while (it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}
