#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

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

  char *words[BUFFER_SIZE];

  int n = 0;
  char buffer[BUFFER_SIZE];

  while(n<4 && scanf("%s",buffer) != EOF) {
    words[n] =strdup(buffer);
    n++;
  }

  for(int i=0;i<4;i++)
      printf("%s\n",words[i]);
  
  return 0;
}
