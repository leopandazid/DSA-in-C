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
    // CODE HERE
    if (users == NULL)
        return NULL;
    else
    {
        if (users->id == key)
            return users;
        else if (key < users->id)
            return search(key, users->left);
        else
            return search(key, users->right);
    }
}

// see document for explanattion
struct node *refineUser(struct node *user, struct node *users)
{
    // CODE HERE
    user->right = NULL;
    user->left = NULL;
    if (users == NULL)
    {
        user->friends[0] = -1;
        user->numfren = 0;
        return user;
    }
    else
    {
        struct node *temp = users;
        while (temp != NULL)
        {
            if (user->id == temp->id)
            {
                user->id++;
                temp = users;
            }
            else if (user->id < temp->id)
                temp = temp->left;
            else
                temp = temp->right;
        }
        int i, j = 0, k;
        for (i = 0; i < user->numfren; i++)
        {
            temp = users;
            while (temp != NULL)
            {
                if (temp->id == user->friends[i])
                {
                    temp->friends[temp->numfren] = user->id;
                    temp->numfren++;
                    break;
                }
                else if (user->friends[i] < temp->id)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if (temp == NULL)
            {
                for (k = i + 1; k < user->numfren; k++)
                    user->friends[k - 1] = user->friends[k];
                user->numfren--;
                i--;
            }
        }
        return user;
    }
}

// insert user with id
struct node *insertUser(struct node *root, int id, struct node *user)
{
    // CODE HERE
    if (root == NULL)
        return user;
    else
    {
        if (id < root->id)
            root->left = insertUser(root->left, user->id, user);
        else
            root->right = insertUser(root->right, user->id, user);
    }
    return root;
}

void printFriends(struct node *user)
{
    int i;
    if (user->numfren == 0)
        printf("-1\n");
    for (i = 0; i < user->numfren; i++)
    {
        printf("%d\n", user->friends[i]);
    }
}

// prints friends list
void friends(int id, struct node *users)
{
    // CODE HERE
    if (users == NULL)
        printf("-1");
    else
    {
        struct node *temp = users;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                printFriends(temp);
                break;
            }
            else if (id < temp->id)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
}

// find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node)
{
    // CODE HERE
    if (node->left == NULL)
        return node;
    else
    {
        struct node *temp = node;
        while (node->left != NULL)
            node = node->left;
        return node;
    }
}

// deletes itself from its friend's nodes
void deleteFriends(int key, struct node *users)
{
    // CODE HERE
    int i, j;
    if (users == NULL)
        return;
    else
    {
        deleteFriends(key, users->left);
        for (i = 0; i < users->numfren; i++)
        {
            if (key == users->friends[i])
            {
                for (j = i + 1; j < users->numfren; j++)
                    users->friends[j - 1] = users->friends[j];
                users->numfren--;
            }
        }
        deleteFriends(key, users->right);
    }
}

void copyUser(struct node *user1, struct node *user2)
{
    user1->id = user2->id;
    user1->numfren = user2->numfren;
    strcpy(user1->name, user2->name);
    int i;
    for (i = 0; i < user1->numfren; i++)
    {
        user1->friends[i] = user2->friends[i];
    }
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    // CODE HERE
    if (root == NULL)
        return root;
    else
    {
        if (key < root->id)
            root->left = deleteNode(root->left, key);
        else if (key > root->id)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                struct node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                struct node *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                struct node *succ = minValueNode(root->right);
                copyUser(root, succ);
                root->right = deleteNode(root->right, succ->id);
                return root;
            }
        }
    }
}

// Print USER's IDs in ascending order
void printInOrder(node *myusers)
{
    // CODE HERE
    if (myusers == NULL)
        return;
    else
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