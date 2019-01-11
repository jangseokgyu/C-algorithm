#include <stdio.h>

typedef struct node {
  int val;
  struct node *prev;
  struct node *next;
}node;

typedef struct list {
  node *head;
  node *tail;
}list;

int main() {
  node a = {1,0,0};
  node b = {2,0,0};
  node c = {3,0,0};
  node d = {4,0,0};

  list str = { 0 , 0 };

  str.head = &a;
  str.tail = &d;
  
  a.prev = NULL;
  a.next = &b;
  
  b.prev = &a;
  b.next = &c;

  c.prev = &b;
  c.next = &d;
  
  d.prev = &c;
  d.next = NULL;

  printf("%d",str.head->next->next->val);

  return 0;
}
