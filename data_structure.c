#include <stdio.h>
#include <stdlib.h>

typedef struct fuck {
  int val;
  struct fuck *next;
}fuckyou;

int main() {
  fuckyou a = {12,0};
  fuckyou b = {14,0};

  a.next = &b;

  a.next->val = 16;

  printf("%d",a.next->val);

  int *as = malloc(sizeof(int)*4);
  as[0] = 1;
  as[1] = 2;
  as[2] = 3;
  as[3] = 4;

  printf("\n%d",*(as+2));
  return 0;
}
