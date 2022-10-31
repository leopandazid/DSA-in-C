#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}

//search for user with id=key
struct node* search(int key, struct node *users)
{
    if (users == NULL)
		return NULL;
	if (key == users->id)
		return users;
	if (key < users->id)
		return search(key, users->left);
	else
		return search(key, users->right);
}

//see document for explanattion
struct node* refineUser(struct node*user, struct node *users)
{
    user->left=NULL;
    user->right=NULL;
    struct node* temp = search(user->id,users);
    while(temp!=NULL){
        user->id++;
        temp = search(user->id,users);
    }
    int *friendlist = (int*)malloc(sizeof(int)*100);
    int j = 0;
    for(int i=0;i<user->numfren;i++){
        struct node* current = search(user->friends[i],users);
        if(current==NULL){
            continue;
        }
        else{
            current->friends[current->numfren]=user->id;
            current->numfren++;
            friendlist[j]=current->id;
            j++;
        }
    }
    if(j==0){
        user->numfren=0;
        user->friends[user->numfren]=-1;
        return user;
    }
    else{
        user->friends = friendlist;
        user->numfren = j;
        return user;
    }
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
    if (root == NULL)
	{
		root = user;
		return root;
	}
    else{
        node *p = root;
        node *q = NULL;
        while (p != NULL)
        {
            q = p;
            if (user->id < p->id)
                p = p->left;
            else
                p = p->right;
        }
        if (user->id < q->id)
            q->left = user;
        else
            q->right = user;
        return root;
    }
}

//prints friends list
void friends(int id, struct node *users) 
{
    node* temp = search(id,users);
    if(temp->numfren==0){
        printf("-1\n");
    }
    else{
        for(int i=0; i<temp->numfren;i++)
        {
            printf("%d\n",temp->friends[i]);
        }
    }
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
    struct node* temp = node;
    while (temp && temp->left != NULL)
        temp = temp->left; 
    return temp;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    struct node* current = search(key,users);
    for(int i=0;i<current->numfren;i++){
        struct node* friender = search(current->friends[i],users);
        int *friendarr = (int*)malloc(sizeof(int)*100);
        int k = 0;
        for(int j=0;j<friender->numfren;j++){
            if(key==friender->friends[j]){
                continue;
            }
            else{
                friendarr[k]=friender->friends[j];
                k++;
            }
        }
        friender->friends=friendarr;
        friender->numfren=k;
        free(friendarr);
    }
    return users;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->id)
        root->left = deleteNode(root->left, key);
    else if (key > root->id)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->id = temp->id;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    if (myusers != NULL)
	{
		printInOrder(myusers->left);
		printf("%d %s\n",myusers->id,myusers->name);
		printInOrder(myusers->right);
	}
}

int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {
        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:

                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }
    }
    return 0;
}