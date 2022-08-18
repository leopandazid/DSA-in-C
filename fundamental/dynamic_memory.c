/*
size_t -a typedef for unsigned int 
typedef unsigned int size_t;

void* malloc(size_t size); 

malloc returns a void pointer - it takes some integer value (no. of bytes)
allocation takes place on heap
the memory allocation for the ptr that we store the address for memory allocation 
in heap is stored in stack segment of the memory

void free (void *ptr);
void ptr- generic pointer
// pass the starting address of the pointer

after free(ptr ) - ptr becomes a dangling pointer

void* calloc(size_t nmemb, size_t size);

calloc values is initialized to 0, 0.0, ''//null character, etc
malloc values is initialized to junk values

void* realloc(void *ptr,size_t new_size);
*/

#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int *ptr = malloc(sizeof(int)); 
    //int *ptr= (int*) malloc (sizeof(int));

    return 0;
}




