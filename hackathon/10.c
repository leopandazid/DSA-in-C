// Implement hashing, where the collision is resolved using linear probing.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int hash(int key)
{
    return key % MAX;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % MAX] != 0)
        i++;
    return (index + i) % MAX;
}

void Insert(int H[], int key)
{
    int index = hash(key);

    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}

int Search(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % MAX] != key)
        i++;
    return (index + i) % MAX;
}

int main()
{
    int HT[MAX] = {0};
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);

    printf("Key found at %d\n", Search(HT, 35));

    return 0;
}