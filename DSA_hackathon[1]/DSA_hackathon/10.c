// 10) Implement hashing, where the collision is resolved using linear probing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// https://www.youtube.com/watch?v=2Ti5yvumFTU

// hash table is a dsa
/*
Lists or linked list takes O(n) time

hash table finds in O(1)

Hash table is basically an array with a hash function

Hash function takes some input and the map that input to a location 
in our array

eg-
Hash func takes a string and maps it to an integer and it is going to be the index of the array

1. calling the hash function on the same input should always produce the same output
2. Hash function should be fast.
3. hash functions results should be random




*/

#define MAX_NAME 256
#define TABLE_SIZE 10
// #define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
    // ... other stuffs
} person;

person * hash_table[TABLE_SIZE]; // array of pointers pointing to different memory loc
// It is easier to spot when there is a vacancy in the hash table using NULL pointer
// and we don't need space for the full table



unsigned int hash (char *name){
    // lets try to implement 
    // something with some relation to checksum
    unsigned int hash_value = 0;
    int length = strlen(name);

    for (int i=0;i<length;i++){
        hash_value=hash_value+ name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE; 
        // check for this modulus operator
    }

    return hash_value;
}
// we use linear probing to solve the collision problem that we are facing in the hash table

// quarditic probing, external chaining,

bool hash_table_insert(person *p){
    if(p==NULL)
        return false;
    int index = hash (p->name);
    for (int i =0; i< TABLE_SIZE ; i++){
        int try =(i+index)%TABLE_SIZE;
        if (hash_table[try]==NULL){
            hash_table[try]=p;
            return true;
        }
    }
    return false;

    // if (hash_table[index]!=NULL){

    //     return false;
    // }
    // else{
    //     hash_table[index]= p;
    //     return true;
    // }

}

person *hash_table_delete(char *name){
    int index =hash (name);

    for(int i =0;i<TABLE_SIZE;i++){
        int try = (index + i) %TABLE_SIZE;
        if (hash_table[try] !=NULL &&
            strcmp (hash_table[try]->name,name) ==0){
                person *tmp = hash_table[try];
                hash_table[try]=NULL;
                return tmp;
        }
    }
    return NULL;    
}


bool init_hash_table(){
    for (int i=0; i<TABLE_SIZE;i++){
        hash_table[i]=NULL;
    }
    // table is empty

}

// find a person in the table
person* hash_table_lookup(char *name){
    int index =hash (name);
    for(int i =0;i<TABLE_SIZE;i++){
        int try = (index + i) %TABLE_SIZE;
        if (hash_table[try] !=NULL &&
            strcmp (hash_table[try]->name,name) ==0){
                return hash_table[try];
        }
    }
    return NULL;
}



void print_table(){
    for (int i=0; i<TABLE_SIZE;i++){
        if (hash_table[i]==NULL){
            printf("\n%i\t---",i);
        }
        else {
            printf("\n\t%i\t%s\n",i,hash_table[i]->name);
        }
    }
}


int main(int argc, char const *argv[])
{
    init_hash_table();
    // printf("Jacob=> %u \n", hash("Jacob"));
    // printf("Sara=> %u \n", hash("Sara"));
    // printf("Mpho=> %u \n", hash("Mpho"));
    // printf("Shreya=> %u \n", hash("Shreya"));
    // printf("Adrijaa=> %u \n", hash("Adrijaa")); // collision can occur

    person jacob = {.name = "Jacob", .age= 25};
    person jane = {.name = "Jane", .age= 27};
    person jannet = {.name = "Jannet", .age= 35};
    person mylo = {.name = "Mplsfdgo", .age= 20};
    person shreya = {.name = "Shreyya", .age= 19};
    person adrija = {.name = "Adrija", .age= 29};
    person robert = {.name = "Robert", .age= 21};
    person ajax = {.name = "Ajax", .age= 28};



    hash_table_insert(&jacob);
    // hash_table_insert(&jane);
    hash_table_insert(&ajax);
    hash_table_insert(&robert);
    hash_table_insert(&jane);

    hash_table_insert(&jannet);
    print_table();
    hash_table_insert(&mylo);
    hash_table_insert(&shreya);
    hash_table_insert(&adrija);

    print_table();

    // constant time operation - O(1)

    person *tmp = hash_table_lookup("Shreya");
    if (tmp==NULL){
        printf("\nNot Found\n");
    }
    else{
        printf("\nFound %s \n",tmp->name);
    }
    tmp = hash_table_lookup("Shreyya");
    if (tmp==NULL){
        printf("Not Found\n");
    }
    else{
        printf("Found %s \n",tmp->name);
    }

    hash_table_delete("Jane");
    tmp = hash_table_lookup("Jane");
    if (tmp==NULL){
        printf("Not Found\n");
    }
    else{
        printf("Found %s \n",tmp->name);
    }

    print_table();
    
    return 0;
}