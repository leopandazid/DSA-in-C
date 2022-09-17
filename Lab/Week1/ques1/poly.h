typedef struct Node
{
	int coeff;
	int px;
	int py;
	struct Node* next;
}node;

void del(node **head);
void readPolynomial(struct Node** poly);
void displayPolynomial(struct Node* poly);
void addPolynomials(struct Node** result, struct Node* first, struct Node* second);



