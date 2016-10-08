// Calvin Vuong
// MKS65 pd10
// Work 2
// 10-07-2016

#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

// prints out all elements in the list
// takes a pointer to a node struct as a parameter
void print_list( struct node *n ) {
  printf("[");
  while ( (*n).next != NULL ) { // while there is still a next element
    printf( "%d,", (*n).i );
    n++;
  }
  printf("%d]\n", (*n).i);
  
}


void test_print_list() {

  struct node e3;
  struct node e2;
  struct node e1;

  e3.i = 4;
  e3.next = NULL;
  e2.i = 2;
  e2.next = &e3;
  e1.i = 1;
  e1.next = &e2;

  print_list(&e1);
  
}

int main() {
  test_print_list();
  
  return 0;
}
