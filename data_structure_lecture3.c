#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_line_with_compression(char compressed[],int limit);

int main() { 
  char buffer[40];
  int k;
  while(1) {
    fgets(buffer,40,stdin);
    k = read_line_with_compression(buffer, 40);  
    printf("%s:%d\n",buffer,k);
  }

  return 0;    
}

int read_line_with_compression(char compressed[],int limit) {
  int ch, i =0;
  while((ch = getchar()) != '\n') {
    if(i<limit-1 && (!isspace(ch) || (i>0 && !isspace(compressed[i-1])))) {
      compressed[i] = ch;
      i++;
    }
    if(i>0 && isspace(compressed[i-1]))
       i--;
  }
    compressed[i] = '\0';
    return i;
}
