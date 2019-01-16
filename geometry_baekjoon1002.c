#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print(char * s1) {
  char *s2 = (char*)malloc(sizeof(char)*2);
  double x1,y1,r1,x2,y2,r2;
  double r_ab;
  scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);

  r_ab = sqrt(pow(x1-x2,2)+pow(y1-y2,2));

  if(x1 == x2 && y1 == y2) {//터렛 좌표가 같은 경우
    if(r1 == r2) {// 적의 거리가 같은 경우
      sprintf(s2, "%d/n",-1);
      strcpy(s1, s2);
      }
    else {
      sprintf(s2, "%d/n",0);
      strcpy(s1, s2);
      }
  }
}

int main() {
  int num;
  char *s1 = (char*)malloc(sizeof(char)*1000);
  scanf("%d",&num);
  scanf("%*c");

  for(int i=0;i<num;i++) {
    print();
  }
  return 0;
}
