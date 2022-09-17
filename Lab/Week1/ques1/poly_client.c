#include<stdio.h>
#include<stdlib.h>
#include"poly.h"

int main()
{

	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* result = NULL;

	printf("\nEnter the corresponding data:-\n");
	printf("\nFirst polynomial:\n");
	readPolynomial(&first);
	displayPolynomial(first);
	printf("\nSecond polynomial:\n");
	readPolynomial(&second);
	displayPolynomial(second);
	addPolynomials(&result, first, second);
	displayPolynomial(result);
	
	del(&result);
	return 0;
}