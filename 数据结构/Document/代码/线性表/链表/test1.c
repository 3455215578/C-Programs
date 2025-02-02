#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node *next;
}Node;

//初化链表
Node* initList()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

int main(int argc, char const *argv[])
{
	Node *list = initList();
	return 0;
}