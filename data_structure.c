#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
}nod;

int main() {
  nod a = {12,0}, b = {10,0};
  nod *head = &a;
  a.next = &b;

  a.next->val = 12;

  return 0;
}
