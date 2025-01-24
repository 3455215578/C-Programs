#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** ǰ������ **/
typedef struct node
{
	ElemType data;
	struct node* next;
}Node;

/** ����ֻ��ͷ�ڵ������ **/
Node* Create_HeadNode(void)
{
	Node* head = (Node*)malloc(sizeof(Node));

	head->data = 0;

	head->next = NULL;

	return head;
}


/** �������� **/
void Travel_List(Node* head)
{
	// ��nodeָ��node1
	Node* node = head->next;

	while (node != NULL)
	{
		printf("%d\n", node->data);

		node = node->next;
	}

	printf("\n");
}

/** ��ȡβ�ڵ� **/
Node* Get_TailNode(Node* head)
{
	Node* node = head;

	while (node->next != NULL)
	{
		node = node->next;
	}

	return node;
}

/** β�巨 **/

void Insert_Tail(Node* head, ElemType element)
{
	Node* tail_node = Get_TailNode(head);

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	new_node->next = tail_node->next;

	tail_node->next = new_node;

}


/** ��ȡ������ **/
int Get_Length(Node* head)
{
	Node* node = head;
	int length = 0;

	while (node != NULL)
	{
		length++;
		node = node->next;
	}

	return length;
}


// Head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

// pre           curr  
// NULL    Head -> 1 ->  2 -> 3 -> 4 -> 5 -> 6 -> NULL

/** ����ת **/
void* Reverse_List(Node* head)
{
	Node* prev = NULL;
	Node* curr = head->next;
	Node* next; // ��currָ��prevʱ, next�������Ӻ���Ľڵ�

	// �ڵ��ƶ���˳��
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head->next = prev;

}

int main(void)
{
	Node* list = Create_HeadNode();

	Insert_Tail(list, 1);
	Insert_Tail(list, 2);
	Insert_Tail(list, 3);
	Insert_Tail(list, 4);
	Insert_Tail(list, 5);
	Insert_Tail(list, 6);

	Travel_List(list);

	Reverse_List(list);

	Travel_List(list);

	return 0;
}