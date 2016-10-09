// Calvin Vuong
// MKS65 pd10
// Work 2
// 10-07-2016
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

// prints out all elements in the list
// takes a pointer to a node struct as a parameter
void print_list( struct node *n ) {
  printf("[");
  while ( (*n).next != NULL ) { // while there is still a next element
    printf( "%d,", (*n).i );
    n = (*n).next;
  }
  printf("%d]\n", (*n).i);
  
}


// takes a pointer to the existing list and the data to be added
// puts a new node with the new data at the beginning of the list
// return a pointer to the beginning of the list
struct node * insert_front(struct node *list, int data) {
  struct node *new = (struct node *) malloc(sizeof(struct node));;
  (*new).i = data;
  (*new).next = list;

  return new;

}

// takes a pointer to a list as a parameter
// frees each node and return a pointer to the beginning of the list (which should be NULL by then). 
struct node * free_list(struct node *list) {
  while ( list != NULL ) {
    struct node * tmp_ptr = (*list).next;
    free(list);
    list = tmp_ptr;
  }

  return NULL;
}

void test_print_list() {
  struct node n3;
  struct node n2;
  struct node n1;

  n3.i = 4;
  n3.next = NULL;
  n2.i = 2;
  n2.next = &n3;
  n1.i = 1;
  n1.next = &n2;

  print_list(&n1);
  
}

void test_insert_front() {
  struct node *n3 = (struct node *) malloc(sizeof(struct node));
  struct node *n2 = (struct node *) malloc(sizeof(struct node));
  struct node *n1 = (struct node *) malloc(sizeof(struct node));

  (*n3).i = 27;
  (*n3).next = NULL;
  (*n2).i = 9;
  (*n2).next = n3;
  (*n1).i = 3;
  (*n1).next = n2;

  printf("List before insertion: ");
  print_list(n1);

  printf("List after inserting 1 at front: ");
  print_list( insert_front(n1, 1) );
}

void test_free_list() {
  struct node *n3 = (struct node *) malloc(sizeof(struct node));
  struct node *n2 = (struct node *) malloc(sizeof(struct node));
  struct node *n1 = (struct node *) malloc(sizeof(struct node));

  (*n3).i = 27;
  (*n3).next = NULL;
  (*n2).i = 9;
  (*n2).next = n3;
  (*n1).i = 3;
  (*n1).next = n2;

}

int main() {
  test_print_list();
  test_insert_front();
  test_free_list();
  
  return 0;
}
