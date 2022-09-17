/*
Prints RAM
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char *ptr;
    *ptr = (int*) malloc(30);
    strcpy(ptr,"RAM");
    printf("%s",ptr);
    free(ptr);
    return 0;
}
