/*
List : Abstract Data Type(ADT) and Array List, Linked List

ADT- a class of objects whose logical behaviour is defined by a set of values and a set of operations

// Abstract Data Type (linked list)
List - represents a countable number of ordered values where same value may occur more than once
Items have a position/ index
List has a size
can grow and shrink in size
list cannot have gaps in between

pre-condition - set of conditions wrt to the parameters of a condition
post-condition - set of conditions after function has been executed, and function is doing what is required

*/

#include<stdlib.h>
#include<stdio.h>

typedef struct List{
    int data;
    struct List *next;
}List;

void CreateList(List *list){

}

