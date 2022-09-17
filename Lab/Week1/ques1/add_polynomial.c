#include<stdio.h>
#include<stdlib.h>

//Making struct for poly
struct poly
{
    int c;
    int px;
    int py;
    struct poly *next;
};
typedef struct poly poly_t;

//Making struct for the list
struct list
{
    poly_t *h;
};
typedef struct list poly_list;

//initialize the list
void init_list(poly_list *l)
{
    l->h = NULL;
}

//insert polynomials
void insert_poly(poly_list *l)
{
    int c,x,y;

     while (1)
    {
        printf("\nEnter the coefficient: ");
        scanf("%d",&c);
        if(c==0)
        {
            break;
        }
        printf("\nEnter the power of variable x: ");
        scanf("%d",&x);
        printf("\nEnter the power of variable y: ");
        scanf("%d",&y);


        //Node with input
        poly_t *t = (poly_t*)malloc(sizeof(poly_t));
        t->c = c;
        t->px = x;
        t->py = y;
        t->next = NULL;

        if(l->h==NULL)
        {
            l->h = t;
        }
        else
        {
            t->next = l->h;
            l->h = t;
        }
        printf("Elements inserted\n");
     
    }
    
}

//Function to add polynomials
void add(poly_list *l1, poly_list *l2)
{
    if(l1->h==NULL || l2->h==NULL)
    {
        printf("Cannot add empty lists\n");
    }
    else
    {
        poly_t *t1;
        t1 = (poly_t*)malloc(sizeof(poly_t));
        t1 = l1->h;

        poly_t *t2;
        t2 = (poly_t*)malloc(sizeof(poly_t));
        t2 = l2->h;

        printf("After adding:\n");
        while(t1!=NULL && t2!=NULL)
        {
            int sum_c = 0;

            if(t1->px==t2->px && t1->px==t2->py)
           {
                
                sum_c = t1->c + t2->c;
                printf("%dx^%dy^%d+",sum_c,t1->px,t1->py);

                t1 = t1->next;
                t2 = t2->next;
            }
            else if(t1->px>t2->px && t1->py>t2->py)
            {
                printf("%dx^%dy^%d+",t1->c,t1->px,t1->py);
                t1 = t1->next;
            }
            else if(t1->px<t2->px && t1->py<t2->py)
            {
                printf("%dx^%dy^%d\n",t2->c,t2->px,t2->py);
                t2 = t2->next;
            }
            else
            {
                printf("%dx^%dy^%d+",t1->c,t1->px,t1->py);
                printf("%dx^%dy^%d\n",t2->c,t2->px,t2->py);
                break;
            }
        } 
        if(t1!=NULL)
        {
            while(t1!=NULL)
            {
                printf("%dx^%dy^%d+",t1->c,t1->px,t1->py);
                t1 = t1->next;
            }
        }
        if(t2!=NULL) 
        {
            while(t2!=NULL)
            {
                printf("%dx^%dy^%d\n",t2->c,t2->px,t2->py);
                t2 = t2->next;
            }
        }     

        free(t1);
        free(t2);
    }
    
}



int main()
{
    poly_list l1;
    init_list(&l1);

    poly_list l2;
    init_list(&l2);

    //Menu
    int selection;
    while(1)
    {
        printf("\n1->Insert the first polynomial\n");
        printf("2->Insert the second polynomial\n");
        printf("3->Add the polynomials\n");
        printf("4->Exit\n");
        scanf("%d",&selection);

        switch (selection)
        {
        case 1: insert_poly(&l1);
                break;
        case 2: insert_poly(&l2);
                break;
        case 3: add(&l1,&l2);
                break;
        case 4: exit(0);
        default: printf("Invalid selection\n");
        }
    }

    return 0;
}
 