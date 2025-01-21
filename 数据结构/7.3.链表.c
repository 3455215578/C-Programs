#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** ǰ������ **/
typedef struct node
{
	ElemType data;
	struct node* next; // �ڽṹ�嶨�屻���֮ǰ����������֪�� Node ��һ�����ͱ���
}Node;

Node* Init_Node(void)
{
	// ����ͷ�ڵ�
	//  data: 0;
	//  next: NULL
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;

	return head;
}

/**

	+����������������������+    +����������������������������������+	 +��������������������������������+
	| 0 | node1 |    | element | node2 |	 | element | next |
	+����������������������+    +����������������������������������+	 +��������������������������������+
		head              node1		              node2

**/


/** �������� **/
/** �ƽڵ㣺���������ͷ�������洢���ݵĽڵ� **/
/** �ڰ����ƽڵ�������У�"ͷ�ڵ�"ָ��������ƽڵ㱾����"��һ���ڵ�"����ָ�ƽڵ�֮��ĵ�һ��ʵ�����ݽڵ㡣 **/
void Travel_Node(Node* head)
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

/**

// ԭ����ͷ�ڵ�
				+��������������������+
	head     :  | 0 | NULL |
				+��������������������+


// 1.�����½ڵ㣬����������ֵ
				+��������������������������������+
	new_node : 	| element |      |
				+��������������������������������+


// 2.��ԭ��ͷ�ڵ��ָ����ֵ���½ڵ��ָ����
				+��������������������+
	head     :  | 0 | NULL |
				+��������������������+

				+��������������������������������+
	new_node : 	| element | NULL |
				+��������������������������������+

// 3.��ԭ��ͷ�ڵ��ָ����ָ���½ڵ�
				+����������������������������+
	head     :  | 0 | new_node |
				+����������������������������+

				+��������������������������������+
	new_node : 	| element | NULL |
				+��������������������������������+

**/


/** ����ڵ� -- 1.ͷ�巨 **/
/** ÿ�ζ���ͷ�ڵ�֮������½ڵ� **/
void Insert_Head(Node* head, ElemType element)
{
	// 1.�ڶ��ڴ��д����½ڵ㣬��������������ֵ            
	Node* new_node = (Node*)malloc(sizeof(Node));        
	new_node->data = element; 

	// 2.��ͷ�ڵ��ָ����ֵ���½ڵ�
	new_node->next = head->next;

	// 3.��ͷ�ڵ�ָ���½ڵ�
	head->next = new_node;
}

/** ��ȡβ�ڵ� **/
Node* Get_TailNode(Node* head)
{
	Node* node = head->next;
	while (node != NULL)
	{
		node = node->next;
	}

	return node;
}

/** ����ڵ� -- 2.β�巨 **/
/** ���½ڵ���Ϊ�µ�β�ڵ� **/
void Insert_Tail(Node* tail, ElemType element)
{
	// 1.�ڶ��ڴ��д����½ڵ㣬��������������ֵ            
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;



	// 2.��β�ڵ��ָ����ֵ���½ڵ�
	new_node->next = NULL;



}

int main(void)
{
	// ��ʼ������(�˿�ֻ��ͷ�ڵ�)
	Node* list = Init_Node();

	Insert_Head(list, 10);
	Insert_Head(list, 20);
	Insert_Head(list, 30);

	Travel_Node(list);

	return 0;
}