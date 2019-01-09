/*입력시 100까지 n을 받으므로*/
#include <stdio.h>

void TowerofHanoi(int n,int a,int b, int c) {
  if(n==1) {
    printf("%d %d",a,b);
    return;
  }
  TowerofHanoi(n-1,a,c,b);

  printf("\n%d %d\n",a,b);

  TowerofHanoi(n-1,c,b,a);
}

int main() {
  int a = 1,b = 2,c = 3;
  int n;
  int num;
  int q, r;
  unsigned short sum[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  char result[100];
  int count;
  int i;
  scanf("%d",&n);
  q = 7 - n/16;
  r = n%16;

    sum[q] = 1<<r;

    result[99] = '\0';
    for (count=98; sum[0]|sum[1]|sum[2]|sum[3]|sum[4]|sum[5]|sum[6]|sum[7]; count--)
    {
        r = 0;
        for (i=0;i<8;i++)
        {
            num = sum[i] + (r<<16);
            sum[i] = num/10;
            r = num%10;
        }
        result[count] = r + '0';
    }
  result[98] = result[98] - 1;
  
  printf("%s\n", &result[count+1]);
  if(n<=20) {
  TowerofHanoi(n,a,c,b);
  }
  return 0;
}
