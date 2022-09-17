#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int pow1;
    int pow2;
    int coeff;
    struct poly *next;
};

struct poly *poly1 = NULL;
struct poly *poly2 = NULL;
struct poly *polys = NULL;

struct poly *p_insert(int x, int y, int c, struct poly *p)
{
    struct poly *temp = (struct poly *)malloc(sizeof(struct poly));
    temp->pow1 = x;
    temp->pow2 = y;
    temp->coeff = c;
    temp->next = NULL;
    if (p == NULL)
    {
        p = temp;
        return p;
    }
    struct poly *ptr = p;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return p;
}

void show(struct poly *p)
{
    if (p == NULL)
    {
        printf("Polynomial is Empty!\n");
        return;
    }
    struct poly *head = p;
    while (head != NULL)
    {
        printf("%dx^%dy^%d", head->coeff, head->pow1, head->pow2);
        if (head->next != NULL)
        {
            printf(" + ");
        }
        head = head->next;
    }
}

struct poly *poly_add(struct poly *p1, struct poly *p2)
{
    struct poly *to_p1 = p1;
    struct poly *to_p2 = p2;
    struct poly *sum = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if ((p1->pow1 == p2->pow1) && (p1->pow2 == p2->pow2))
        {
            if (p1->coeff + p2->coeff != 0)
            {
                sum = p_insert(p1->pow1, p1->pow2, p1->coeff + p2->coeff, sum);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->coeff + p2->coeff == 0)
            {
                p1 = p1->next;
                p2 = p2->next;
                continue;
            }
        }
        else if (((p1->pow1 > p2->pow1) || (p1->pow1 == p2->pow1)) && ((p1->pow2 > p2->pow2) || (p1->pow2 == p2->pow2)))
        {
            sum = p_insert(p1->pow1, p1->pow2, p1->coeff, sum);
            p1 = p1->next;
        }
        else
        {
            sum = p_insert(p2->pow1, p2->pow2, p2->coeff, sum);
            p2 = p2->next;
        }
    }
    struct poly *last_sum = sum;
    while (last_sum->next != NULL)
    {
        last_sum = last_sum->next;
    }
    if (p1 != NULL)
    {
        last_sum->next = p1;
    }
    else if (p2 != NULL)
    {
        last_sum->next = p2;
    }
    p1 = to_p1;
    p2 = to_p2;
    return sum;
}

int main()
{
    int x, y, c;
    printf("Enter Coeff, Power of x,y for Poly 1:\n");
    scanf("%d %d %d", &c, &x, &y);
    while (c != 0)
    {
        poly1 = p_insert(x, y, c, poly1);
        printf("Enter Coeff, Power of x,y for Poly 1:\n");
        scanf("%d %d %d", &c, &x, &y);
    }

    printf("Enter Coeff, Power of x,y for Poly 2: \n");
    scanf("%d %d %d", &c, &x, &y);
    while (c != 0)
    {
        poly2 = p_insert(x, y, c, poly2);
        printf("Enter Coeff, Power of x,y for Poly 2:\n");
        scanf("%d %d %d", &c, &x, &y);
    }

    printf("\npolynomial 1:\n");
    show(poly1);

    printf("\npolynomial 2:\n");
    show(poly2);

    polys = poly_add(poly1, poly2);

    printf("\n");
    printf("\nSum of the polynomial\n");
    show(polys);

    printf("\n");
    return 0;
}
