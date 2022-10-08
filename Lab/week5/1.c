#include <stdio.h>
#include <stdlib.h>

int check=0;
int found=0;
//struct for node
struct node {
    char *value;            // all void* types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

int my_strlen(char * s) 
{
    int i=0;
    while (s[i]!=0){
        i++;
    }      
    return ++i;
}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    while (*str2 != 0){
        *str1= *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';    
}

int my_strcmp(const char *a, const char *b)
{   int flag=0;
    while(*a && *b){
        if (*a>*b){
            return 1;
        }
        if(*a < *b){
            return -1;
        }
        a++;
        b++;
    }
    return 0; // if it's same
}

struct node* createNode(char *key)
{
	struct node *newNode=malloc(sizeof(struct node));
	my_strcpy(newNode->value,key);
	newNode->p_left=NULL;
	newNode->p_right=NULL;
	
	return newNode;
}

//inserts elements into the tree
void insert(char* key, struct node** leaf)
{
    struct node* newNode =createNode(key); 
    if((*leaf)==NULL)
		return newNode;
	else if(newNode->value < (*leaf)->value)
		(*leaf)->p_left=insertNodeRec((*leaf)->p_left,newNode);
	else
		(*leaf)->p_right=insertNodeRec((*leaf)->p_right,newNode);
	
}




//recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    if(root!=NULL)
	{
		asc_order(root->p_left);
		printf("%d ",root->value);
		asc_order(root->p_right);
	}
    
}



//searches elements in the tree
void search(char* key, struct node* leaf)  // no need for **
{
    found=-1;
    if(key==NULL)
		return;
	else if(my_strcmp(key,leaf->value)==0){
        found =key;
		return;
    }
	else if(my_strcmp(key, leaf->value) < 0 )
		return searchRec(leaf->p_left,key);
	else
		return searchRec(leaf->p_right,key);
    
}




int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++) 
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i],&p_root);
    }   
    char searchname[temp];
    scanf("%s",searchname);

    //checking inorder print
    asc_order(p_root);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_root);
    printf("%d\n",found);
    return 0;
}