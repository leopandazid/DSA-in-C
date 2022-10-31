#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100

typedef struct node
{
    int id;             // ID of user
    int numfren;        // number of friends of user
    char name[MAX];     // name of user
    int *friends;       // friends of user as an array
    struct node *right; // user to the right
    struct node *left;  // user to the left
} node;

struct node *retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    // copied ID
    char *token = strtok(str, ",");
    strcpy(ID, token);

    // copied Name
    token = strtok(NULL, ",");
    strcpy(name, token);

    // copied friends' ID
    token = strtok(NULL, ",");
    strcpy(strfriends, token);
    // printf("%s\n",(strfriends));

    // creating user nodes
    int id = atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id = id;
    user->friends = (int *)malloc(MAX * sizeof(int));
    strcpy(user->name, name);

    // adding user's friend's IDs
    token = strtok(strfriends, "|");
    int i = 0;
    while (token != NULL)
    {

        int temp = atoi(token);
        user->friends[i] = temp;
        i++;
        token = strtok(NULL, "|");
    }
    user->numfren = i;
    if (i == 0)
    {
        user->friends[i] = -1;
    }

    return user;
}

// search for user with id=key
struct node *search(int key, struct node *users)
{
    node *temp = users;
    while (temp != NULL)
    {
        if (temp->id == key)
        {
            return temp;
        }
        else if (key > temp->id)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return NULL;
}

// see document for explanattion
struct node *refineUser(struct node *user, struct node *users)
{
    user->left = user->right = NULL;
    int i = 0;
    while (i != 1)
        if (search(user->id, users) != NULL)
        {

            (user->id)++;
        }
        else
        {
            i = 1;
        }

    int j = 0;
    while (j != user->numfren)
    {
        node *p = search(user->friends[j], users);
        if (p != NULL)
        {

            j++;
            p->friends[p->numfren] = user->id;
            (p->numfren)++;
        }
        else
        {
            user->friends[user->numfren] = 0;

            for (int k = j; k < user->numfren; k++)
            {
                user->friends[k] = user->friends[k + 1];
            }
            (user->numfren)--;
        }
    }
    if (j == 0)
    {
        user->friends[j] = -1;
    }

    return user;
}

// insert user with id
struct node *insertUser(struct node *root, int id, struct node *user)
{
    node *cur = root;
    if (root == NULL)
    {
        root = user;
    }
    else
    {
        while (1)
        {
            if (id >= cur->id)
            {

                if (cur->right == NULL)
                {
                    cur->right = user;
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
            else if (id < cur->id)
            {
                if (cur->left == NULL)
                {
                    cur->left = user;
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
        }
    }
    return root;
}

// prints friends list
void friends(int id, struct node *users)
{
    node *node_id = search(id, users);
    if (node_id != NULL)
    {
        if (node_id->numfren == 0)
        {
            printf("%d\n", -1);
        }
        else
        {
            for (int i = 0; i < node_id->numfren; i++)
            {
                printf("%d\n", node_id->friends[i]);
            }
        }
    }
    else
    {
        printf("%d\n", -1);
    }
}

//find child node with minimum value (inorder successor) - helper to delete node
 struct node *minValueNode(struct node *node) {
   struct node* pre=node->right;
   while(pre->left!=NULL)
   {
    pre=pre->left;

   }
   return pre;
 }

// deletes itself from its friend's nodes
struct node *deleteFriends(int key, struct node *users)
{
    node *find = search(key, users);
    if (find == NULL)
        return users;

    for (int i = 0; i < find->numfren; i++)
    {
        node *temp = search(find->friends[i], users);
        for (int j = 0; j < temp->numfren; j++)
        {
            if (temp->friends[j] == key)
            {
                temp->friends[temp->numfren] = 0;
                for (int k = j; k < temp->numfren; k++)
                {
                    temp->friends[k] = temp->friends[k + 1];
                }
                --temp->numfren;
                break;
            }
            else
                j++;
        }
    }

    return users;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{

    if (root == NULL)
    {
        printf("empty!!");
    }
    else
    {
        if (key > root->id)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->id)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // node *temp = root->right;
            // while (temp->left != NULL)
            // {
            //     temp = temp->left;
            // }
            node *temp=minValueNode(root);
            root->id = temp->id;
            strcpy(root->name, temp->name);
            root->right = deleteNode(root->right, temp->id);
        }
    }

    return root;
}

// Print USER's IDs in ascending order
void printInOrder(node *myusers)
{
    if (myusers !=NULL)
    {
        printInOrder(myusers->left);
        printf("%d %s\n", myusers->id, myusers->name);
        printInOrder(myusers->right);
    }
}

int main(int argc, char **argv)
{
    node *users = NULL;
    while (1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d", &opt);
        char str[MAX];
        switch (opt)
        {
        case 1:

            scanf("%s", str);
            struct node *tbins = retUser(str);
            tbins = refineUser(tbins, users);

            users = insertUser(users, tbins->id, tbins);
            break;

        case 2:

            scanf("%d", &id);
            deleteFriends(id, users);
            users = deleteNode(users, id);

            break;

        case 3:

            scanf("%d", &id);
            node *result = search(id, users);
            if (result == NULL)
                printf("USER NOT IN TREE.\n");
            else
            {
                printf("%d\n", result->id);
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
