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
    printf("hello");
    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);
    printf("hello");
    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);
    printf("hello");
    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));
    printf("hello");

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);

    printf("hello");

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
    //CODE HERE
    if(users == NULL || users->id == key)
     return users;
    else
    {
        if(key<users->id)
            return search(key,users->left);
        else if(key>users->id)
            return search(key, users->right);
    }
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    //CODE HERE
    while(search(user->id,users)->id != user->id)
        (user->id)++;
    
    int i = 0,j = 0;
    while(i<user->numfren)                        //removing non-existent id's
    {
        if(search(user->friends[i],users) == NULL)
        {
            j = i;
            while(j<(user->numfren-1))
                user->friends[j]=user->friends[++j];
            (user->numfren)--;
        }
        else 
            i++;
    }

    if(user->numfren == 0)
        user->friends[user->numfren] = -1;

    i = 0;
    while(i<user->numfren)                        //adding id to friends' nodes' friends array
    {
        search(user->friends[i],users)->friends[(search(user->friends[i],users)->numfren)++] = user->id;
        i++;
    }
    return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
   //CODE HERE
   if(root == NULL)
    root = user;
   else if (id<root->id)
    root = insertUser(root->left,id,user);
   else
    root = insertUser(root->right,id,user);
   return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
   //CODE HERE
   struct node *user = search(id, users);
   if(user != NULL)
   {
    int i = 0;
    for(i = 0;i<user->numfren;i++)
        printf("%d\n", user->friends[i]);
    if(user->numfren == 0)
        printf("-1\n");
   }

}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
  //CODE HERE
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    //CODE HERE
    struct node *deluser = search(key, users);
    struct node *check = NULL;
    if(deluser!=NULL)
    {
        int *frlist = deluser->friends;
        // int *frlist = (int *) malloc(MAX*)
        int i = 0, j = 0, flag = 0;
        for(i = 0; i<deluser->numfren; i++)
        {
            check = search(frlist[i],users);
            for(j = 0; j<check->numfren; j++)
            {
                if(deluser->id == check->friends[i])
                {
                    flag = 1;
                    break;
                }
            }
            for(; j<(check->numfren)-1; j++)
            {
                check->friends[j] = check->friends[j+1];
            }
            if(flag = 1)
            (check->numfren)--;
        }
    }
    return users;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  //CODE HERE

  struct node *prev, *cur,*q, *temp,*p;
  prev = NULL;
  cur = root;

  while(cur!=NULL && cur->id!=key)
  {
    prev = cur;
    if(key<cur->id)
        cur = cur->left;
    else
        cur = cur->right;
  }

  if(cur == NULL)
    return root;

  if(cur->left == NULL||cur->right==NULL)
  {
    if(cur->left==NULL)
        q = cur->left;
    else
        q = cur->right;
    
    if(prev==NULL)
    {
        cur = root;
        free(cur);
        return root;
    }
    if(cur==prev->left)
        prev->left = q;
    else
        prev->right = q;
    free(cur);
  }
  else
  {
    p = NULL;
    temp = cur->right;
    while(temp->left!=NULL)
    {
        p = temp;
        temp = temp->left;
    }
    cur->id = temp->id;
    if(p!=NULL)
        p->left = temp->right;
    else
        cur->right = temp->right;
    free(temp);
  }
  return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    //CODE HERE
    if(myusers!=NULL)
    {
        printInOrder(myusers->left);
        printf("%d %s\n", myusers->id, myusers->name);
        printInOrder(myusers->right);
    }
    return;
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