#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** ǰ������ **/
typedef struct node
{
	ElemType data;
	struct node *prev, *next; // �ڽṹ�嶨�屻���֮ǰ����������֪�� Node ��һ�����ͱ���
	// nextָ����ǽڵ�
}Node;

/** ����ͷ�ڵ� **/
Node* Create_HeadNode(void)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

/** ͷ�巨 **/
void Insert_Head(Node* head, ElemType element)
{
	Node* node = (Node*)malloc(sizeof(Node));

	// ������ֵ
	node->data = element;

	// �½ڵ��prev��nextָ��
	node->prev = head;
	node->next = head->next;

	// ԭ�ڵ�ָ��
	if (head->next != NULL)
	{
		head->next->prev = node;
	}

	head->next = node;
}

/** �������� **/
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

void Insert_Tail(Node* head, ElemType element)
{
	// Ѱ��β�ڵ�
	Node* tail_node = Get_TailNode(head);

	// �����½ڵ㲢��ֵ
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;

	// ָ��
	node->prev = tail_node;
	node->next = NULL;
	tail_node->next = node;
}

/** Ѱ��ָ��λ�õ�ǰ���ڵ� **/
Node* Find_PreNode(Node* head, int pos)
{
	if (pos == 0)
	{
		printf("ͷ�ڵ�û��ǰ���ڵ�\n");
		return;
	}

	Node* node = head;

	for (int i = 0; i < pos - 1; i++) // pos=2
	{
		if (node->next == NULL)
		{
			return;
		}

		node = node->next;

	}

	return node;
}

/** ��ָ��λ�ò���ڵ� **/
void Insert_Node(Node* head, int pos, ElemType element)
{
	// Ѱ��ǰ���ڵ�
	Node* pre_node = Find_PreNode(head, pos);

	// �����½ڵ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;

	// ָ��
	node->prev = pre_node;
	node->next = pre_node->next;

	if (pre_node->next != NULL)
	{
		pre_node->next->prev = node;
	}

	pre_node->next = node;

}

/** ɾ��ָ��λ�õĽڵ�, �����ر�ɾ���ڵ�洢������ **/
void Delete_Node(Node* head, int pos, ElemType* delete_data)
{
	// �ҵ���ɾ���ڵ��ǰ���ڵ�
	Node* pre_node = Find_PreNode(head, pos);

	if (pre_node->next == NULL)
	{
		printf("Ҫɾ���Ľڵ㲻����\n");
		return;
	}

	Node* delete_node = pre_node->next;

	// ���汻ɾ���ڵ������
	*delete_data = delete_node->data;

	pre_node->next = delete_node->next;

	free(delete_node);

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

	ElemType delete_data;

	Delete_Node(list, 6, &delete_data);

	Travel_List(list);
	printf("%d\n", delete_data);

	return 0;
}