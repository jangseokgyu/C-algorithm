#include <stdio.h>

int binarysearch(int a[],int size,int num) {
  int i = 0;
  int mid = 0;

  while(i <= size) {
    mid = (i+size)/2;
    if(a[mid]  ==  num) {
       return mid;
    }
    else
    {
      if(num <a[mid])
        size = mid-1;
      else
        i = mid+1;
    }
  }
  return -1;
}

int main() {
  int a[] = {1,5,13,34,64,76,86,88,99};
  int sort = 8;

  int temp = binarysearch(a,7,88);

  if(temp == -1)
     printf("검색결과가 없습니다");
  else
     printf("검색결과 : %d의 위치는 %d",88,temp);

  return 0;
}
