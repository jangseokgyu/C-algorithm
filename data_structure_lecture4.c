#include <stdio.h>

int main() {
  char name[4][10];
  char phone[4][12];

  int i=0;
  int j =0;
  char ch;

  while(1) {
    int temp = i;
    puts("이름을 입력하시오");
    while((ch=getchar()) != '\n') {
       name[i][j] = ch;
       j++;
    }
    name[i][j] = '\0';
    i = temp+1;
    j = 0;
    ch='\0';
    puts("폰번호를 입력하시오");
    while((ch=getchar()) != '\n') {
       phone[i][j] = ch;
       j++;
    }
    fflush(stdin);
    ch = '\0';
    puts("그만할래?");
    while((ch=getchar()) != '\n'){
    }
    if (ch == 'y')
      break;
    
    //ch = '\0';
    //fflush(stdin);

  }
  i = 0;
  j = 0;
  for(i=0;i<4;i++) {
    printf("결과는 : %s\t %s\n",name[i],phone[i]);
    i++;
  }

  return 0;
}
