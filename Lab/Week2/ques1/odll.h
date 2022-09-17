typedef struct student
{
    char srn[14];
    char name[30];
    float cgpa;
} STUDENT;

typedef struct node
{
    STUDENT *s;
    struct node *prev, *next;
} NODE;

void initList(NODE **head);
NODE* newNode(char *srn,char *name,float cgpa);
void SortedInsert(NODE **head,char *srn,char *name,float cgpa);
NODE *search(NODE *head,char *srn);
void display(NODE *p);