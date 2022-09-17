#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void del(node **head)
{
	struct node *temp;
	if (*head == NULL)
	{
		printf("list is empty");
	}
	node *prev = *head;
	node *pres = (*head)->next;
	while (prev != NULL && pres != NULL)
	{
		prev->next = pres->next;
		free(pres);
		prev = prev->next;
		if (prev != NULL)
		{
			pres = prev->next;
		}
	}
}
void readPolynomial(struct Node **poly)
{
	int coeff, px, py, cont;
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	*poly = temp;
	do
	{
		scanf("%d %d %d", &coeff, &px, &py);
		temp->coeff = coeff;
		temp->px = px;
		temp->py = py;
		temp->next = NULL;
		printf("\n enter 0 to exit 1 to continue");
		scanf("%d", &cont);
		if (cont)
		{
			temp->next = (struct Node *)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	} while (cont);
}

void displayPolynomial(struct Node *poly)
{
	printf("\nPolynomial expression is: ");
	while (poly != NULL)
	{
		printf(" %dX^%dY^%d ", poly->coeff, poly->px, poly->py);
		poly = poly->next;
		if (poly != NULL)
			printf("+");
	}
}

void addPolynomials(struct Node **result, struct Node *first, struct Node *second)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->next = NULL;
	*result = temp;
	while (first != NULL && second != NULL)
	{
		// if(first->px > second->px && first->py > second->py)
		// {
		// 	temp->coeff = first->coeff;
		// 	temp->px = first->px;
		// 	temp->py = first->py;
		// 	first = first->next;
		// }
		// else if(first->px < second->px && first->py > second->py)
		// {
		// 	temp->coeff = second->coeff;
		// 	temp->px = second->px;
		// 	temp->py = second->py;
		// 	second = second->next;
		// }
		// else
		// {
		// 	temp->coeff = first->coeff + second->coeff;
		// 	temp->px = first->px;
		// 	temp->py = first->py;
		// 	first = first->next;
		// 	second = second->next;
		// }

		// if(first && second)
		// {
		// 	temp->next = (struct Node*)malloc(sizeof(struct Node));
		// 	temp = temp->next;
		// 	temp->next = NULL;
		// }

		if (first->px + first->py == second->px + second->py)
		{
			if (first->px==second->px && first->py ==second->py){
				temp->coeff=first->coeff+second->coeff;
				temp->px = first->px;
				temp->py = first->py;
				first = first->next;
				second=second->next;
			}
			else if (first->px > second->px){ // power of x is compared first
				temp->coeff = first->coeff;
				temp->px = first->px;
				temp->py = first->py;
				first = first->next;
			}
			else{
				temp->coeff = second->coeff;
				temp->px = second->px;
				temp->py = second->py;
				second = second->next;
			}

		}
		else if (first->px + first->py >= second->px + second->py)
		{
			temp->coeff = first->coeff;
			temp->px = first->px;
			temp->py = first->py;
			first = first->next;
		}
		else{
			temp->coeff = second->coeff;
			temp->px = second->px;
			temp->py = second->py;
			second = second->next;

		}
	}
	while (first != NULL || second != NULL)
	{
		temp->next = (struct Node *)malloc(sizeof(struct Node));
		temp = temp->next;
		temp->next = NULL;

		if (first)
		{
			temp->coeff = first->coeff;
			temp->px = first->px;
			temp->py = first->py;
			first = first->next;
		}

		else if (second)
		{
			temp->coeff = second->coeff;
			temp->px = second->px;
			temp->py = second->py;
			second = second->next;
		}
	}
}
