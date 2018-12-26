#include <stdio.h>

int main() {
  int sort[] = {12,65,34,23,86,54,21,95};
  int index = 8;

  for(int i =0;i<index;i++) {
    int min = i;
    for(int j = i+1; j<index;j++) {
      if(sort[min] > sort[j]) // 여기가 왜 i가 아니라 min인지 이해가 안됨..
         min = j;
    }

    int temp = sort[i];
    sort[i] = sort[min];
    sort[min] = temp;
    for(int x =0;x<index;x++) {
      printf("%d ",sort[x]);
    }
    printf("\n");
  }
}
