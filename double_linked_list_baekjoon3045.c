#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int val;
	struct Node *prev;
	struct Node *next;
} Node;
typedef struct {
	Node *head;
	int size;
} DLL;
Node *newnode(int n)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = n;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}
DLL *newDLL() {
	DLL *temp = (DLL *)malloc(sizeof(DLL));
	temp->head = NULL;
	temp->size = 0;
	return temp;
}
int search(DLL *list, int num) {
  struct Node* temp = list->head;
  while(num--)
    temp = temp->next;
  
  return (temp->val);
}
void append(DLL *list, Node *newnode) {
	struct Node* temp = list->head;
	struct Node* newNode = newnode;
	if (list->head == NULL) {
		list->head = newNode;
		list->size++;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	list->size++;
	temp->next = newNode;
	newNode->prev = temp;
}
void insertAt(DLL *list, int index, Node *newnode) {
	struct Node* temp = list->head;
	if (index == 0) {
		newnode->next = list->head;
		list->head->prev = newnode;
		list->head = newnode;
		list->size++;
	}
	else if (index == list->size) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		newnode->prev = temp;
		newnode->next = NULL;
		temp->next = newnode;
		list->size++;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next->prev = newnode;
		temp->next = newnode;
		list->size++;
	}
}
void deleteAt(DLL *list, int index) {
	struct Node* temp = list->head;
	if (index == 0) {
		temp->next->prev = NULL;
		list->head = temp->next;
		list->size--;
	}
	else if (index + 1 == list->size) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->prev->next = NULL;

		list->size--;
	}
	else {
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		list->size--;
	}
}

void sorting(DLL* list,int size) {
  char* str = (char*)malloc(sizeof(size*size));
  char* s1 = (char*)malloc(sizeof(size*size));

  int count=0,j=0,tempi;
  for(int i=0;i<size;i++){
    if((i+1) != (tempi=search(list,i))){
        insertAt(list, i, newnode(i+1));
        j=i+1;
    while(search(list,j) != i+1){
          j++;
        }
        deleteAt(list,j);
        count++;
        sprintf(s1,"A %d %d\n",j,j+1);
        strcat(str,s1);
    }
  }
  printf("%d\n",count);
  puts(str);
  free(str);
  free(s1);
}
int main() {
  int i,m,n,num1,num2;
  char c;
	DLL *list = newDLL();
  DLL *list2 = newDLL();
	scanf(" %d%d",&n,&m);
  scanf("%*c");
	for (i = 1; i < n+1; i++) {
		append(list, newnode(i));
	}
  while(m--) {
    scanf(" %c%d%d", &c, &num1, &num2);
    scanf("%*c");
    if(c == 'A'){
      insertAt(list,num2-1,newnode(search(list,num1-1)));
      if(num1>num2)
        deleteAt(list,num1);
      else
        deleteAt(list,num1-1);
    }
    else {
      insertAt(list,num2,newnode(search(list,num1-1)));
      if(num1<num2){
        deleteAt(list,num1-1);
      }
      else {
        deleteAt(list,num1);
      }
    }
  }
  struct Node* temp = list->head;
  for (i = 1; i < n+1; i++) {
		append(list2, newnode(temp->val));
    temp = temp->next;
	}
  sorting(list,list->size);
	return 0;
}
