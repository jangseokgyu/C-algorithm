#include <stdio.h>

void binarysearch(int a[],int size,int num) {
  int i = 0;
  int mid = 0;

  while(i <= size) {
    mid = (i+size)/2;
    if(a[mid]  ==  num) {
       printf("검색결과 : %d의 위치는 %d",num,mid);
       break;
    }
    else
    {
      if(num <a[mid])
        size = mid-1;
      else
        i = mid+1;
    }
  }
    if(i> size)
      printf("검색결과가 없습니다");
}

int main() {
  int a[] = {1,5,13,34,64,76,86,88,99};
  int sort = 8;

  binarysearch(a,7,89);

  return 0;
}
