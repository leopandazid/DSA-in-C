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
    if (users == NULL) // user is not present
        return NULL;
    else if (key == users->id)
        return users;
    else if (key < users->id)
        return search(key, users->left);
    else
        return search(key, users->right);
}

// see document for explanattion
struct node *refineUser(struct node *user, struct node *users)
{
    user->left = NULL;
    user->right = NULL;
    struct node *temporary = search(user->id, users); // searching if friend is present or not
    while (temporary != NULL)
    {
        user->id++;
        temporary = search(user->id, users);
    }
    // creating valid friend list after removing the users which are not present in tree
    int *friend_list = (int *)malloc(sizeof(int) * MAX);
    int j = -1;
    for (int i = 0; i < user->numfren; i++)
    {
        struct node *cur = search(user->friends[i], users);
        if (cur == NULL)
        {
            continue;
        }
        else
        {
            j++;
            cur->friends[cur->numfren] = user->id;
            cur->numfren++;
            friend_list[j] = cur->id;
        }
    }

    if (j == -1)
    {
        user->numfren = 0; // no friends present
        user->friends[user->numfren] = -1;
        return user;
    }
    else
    {
        int index = 0;
        for (int i = 0; i <= j; i++)
        { // copying friend list to user->friends
            if (user->id == friend_list[i])
            {
                continue;
            }
            user->friends[index++] = friend_list[i];
        }
        user->numfren = j + 1;
        return user;
    }
}

// insert user with id
struct node *insertUser(struct node *root, int id, struct node *user)
{
    if (root == NULL) // root is empty =>tree doesn't exist
    {
        root = user;
        return root;
    }
    else
    {
        node *ptr = root;
        node *qtr = NULL;
        while (ptr != NULL)
        {
            qtr = ptr;
            if (user->id < ptr->id)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (user->id < qtr->id)
            qtr->left = user;
        else
            qtr->right = user;
        return root;
    }
}

// prints friends list
void friends(int id, struct node *users)
{
    node *temporary = search(id, users);
    if (temporary == NULL)
    { // user is not present
        return;
    }
    else if (temporary->numfren == 0)
    { // no friends
        printf("-1\n");
    }
    else
    {
        for (int it = 0; it < temporary->numfren; it++)
        {
            printf("%d\n", temporary->friends[it]);
        }
    }
}

// find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node)
{
    struct node *temp = node;
    while (temp && temp->left != NULL) // traverse to left
        temp = temp->left;
    return temp;
}

// deletes itself from its friend's nodes
struct node *deleteFriends(int key, struct node *users)
{
    struct node *curr = search(key, users);
    if (curr == NULL)
    {
        return users;
    }
    int *friendarr = (int *)malloc(sizeof(int) * 100);
    for (int i = 0; i < curr->numfren; i++)
    {
        if (curr->id == curr->friends[i])
        {
            continue;
        }
        struct node *dost = search(curr->friends[i], users);
        if (dost == NULL)
        {
            continue;
        }
        int k = 0;
        for (int j = 0; j < dost->numfren; j++)
        {
            if (key == dost->friends[j])
            {
                continue;
            }
            else
            {
                friendarr[k] = dost->friends[j];
                k++;
            }
        }
        dost->friends = friendarr;
        dost->numfren = k;
        // free(friendarr);
    }
    return users;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    else if (key < root->id)
        root->left = deleteNode(root->left, key);
    else if (key > root->id)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            // free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            // free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        root->numfren = temp->numfren;
        for (int i = 0; i < root->numfren; i++)
        {
            root->friends[i] = temp->friends[i];
        }

        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

// Print USER's IDs in ascending order
void printInOrder(node *my_users)
{
    if (my_users != NULL)
    {
        printInOrder(my_users->left);
        printf("%d %s\n", my_users->id, my_users->name);
        printInOrder(my_users->right);
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