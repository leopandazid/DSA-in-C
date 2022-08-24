typedef struct node
{
	int coeff;
	int powx;
	struct node *next;
}NODE;

typedef struct plist
{
	struct node *head;
    struct node *last; // here we use last node to keep track of the last node
}POLYNOMIAL;

void initPolynomial(POLYNOMIAL *pl);
void createPolynomial(POLYNOMIAL *pl);
int addPolynomial(POLYNOMIAL *pl1,POLYNOMIAL *pl2,POLYNOMIAL *pl3);
void display(POLYNOMIAL *pl);
