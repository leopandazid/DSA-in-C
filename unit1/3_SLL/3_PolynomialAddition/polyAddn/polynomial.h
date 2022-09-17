typedef struct Poly{
    int coeff;
    int px;
    int py;
    struct Poly *next; // Pointer to hold address of next node 

}poly;

void initList(poly **head);
void createList(poly **head);
void addPoly(poly *head1,poly *head2, poly **ans);
void display(poly *head);
void destroyPolynomial(poly **head);

