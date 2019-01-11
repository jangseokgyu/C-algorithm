#include <stdio.h>
#include <stdlib.h>

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

	if (index < 0 || index > list->size) {
		printf("INSERT ERROR: Out of Bound\n");
	}
	else if (index == 0) {
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
	/*
	if (temp->next != NULL)
		temp->next->prev = temp;
		*/
}

void deleteAt(DLL *list, int index) {
	//save reference to first link

	struct Node* temp = list->head;

	if (index < 0 || index >= list->size) {
		printf("DELETE ERROR: Out of Bound\n");
	}
	else if (index == 0) {
		temp->next->prev = NULL;
		list->head = temp->next;
		list->size--;
	}
	else if (index + 1 == list->size) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);

		list->size--;
	}

	else {
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);

		list->size--;
	}
	/*if (temp->next != NULL)
		temp->next->prev = temp;
		*/

}

void print(DLL *list) {
	struct Node* temp = list->head;
	printf("Forward: ");
	while (temp != NULL) {
		printf("[%d] ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	DLL *list = newDLL();
  unsigned int i,m,n,num1,num2;
  char c;
  scanf("%u%u",&n,&m);
	for (i = 1; i < n+1; i++) {
		append(list, newnode(i));
	}
	print(list);

  while(m--) {
    scanf("%*c%c%*c%u%*c%u%*c", &c, &num1, &num2);
    fflush(stdin);
    printf("%c %u %u\n",c,num1,num2);
    if(c == 'A'){
      insertAt(list,num2-1,newnode(num1));
      deleteAt(list,num1);
      print(list);
    }
    else {
      insertAt(list,num2+1,newnode(num1));
      deleteAt(list,num1-1);
      print(list);
    }
  }

	return 0;
}
