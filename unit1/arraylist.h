#define MAX 10

typedef struct ArrayList{
    int a[10];
    int last;
}list;

void initList(list *ptr);
int append(list *ptr,int ele);
int deleteLast(list *ptr,int *ele);
void display(list *ptr);