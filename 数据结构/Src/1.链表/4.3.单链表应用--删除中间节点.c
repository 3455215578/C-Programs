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
/** �ƽڵ㣺���������ͷ�������洢���ݵĽڵ� **/
/** �ڰ����ƽڵ�������У�"ͷ�ڵ�"ָ��������ƽڵ㱾����"��һ���ڵ�"����ָ�ƽڵ�֮��ĵ�һ��ʵ�����ݽڵ㡣 **/
void Travel_List(Node* head)
{
	// ��nodeָ��node1
	Node* node = head->next;

	while (node != NULL)
	{
		printf("%d\n", node->data);

		// ����node
		node = node->next; // ��Ϊnode1��ָ����ָ��node2, ������nodeָ��node1��ָ����, ��nodeָ��node2
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

/** �����м�ڵ��ǰ���ڵ� **/
Node* Find_MidPreNode(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;

	while ((fast != NULL) && (fast->next != NULL))
	{
		// ��ָ��һ������������ָ��һ����һ��
		fast = fast->next->next;
		slow = slow->next;
	}

	// ��fastΪ�ջ�fast->nextΪ��ʱ��slowָ���м�ڵ��ǰ���ڵ�
	return slow;
}

Node* Find_MidNode(Node* head)
{
	Node* pre_node = Find_MidPreNode(head);

	return pre_node->next;
}

/** ɾ���м�ڵ�-- ����ָ�� **/
/** ����ż�����ڵ㣬���м俿��Ľڵ㶨Ϊ�м�ڵ� **/
void Delete_MidNode(Node* head)
{
	Node* pre_node = Find_MidPreNode(head);

	Node* mid_node = pre_node->next;

	// ǰ���ڵ�ֱ��ָ���м�ڵ����һ���ڵ�
	pre_node->next = mid_node->next;

	// �ͷ��м�ڵ���ڴ�ռ�
	free(mid_node);
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

	Delete_MidNode(list);

	Travel_List(list);

	return 0;
}