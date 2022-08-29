#define MAX 3
typedef struct arrayList
{
	int a[MAX];
	int last;
}ARLST;

void initList(ARLST *pal);
int append(ARLST *pal,int ele);
int deleteLast(ARLST *pal,int *pele);
void display(ARLST *pal);