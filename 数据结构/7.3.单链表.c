#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** ǰ������ **/
typedef struct node
{
	ElemType data;
	struct node* next; // �ڽṹ�嶨�屻���֮ǰ����������֪�� Node ��һ�����ͱ���
}Node;

Node* Create_HeadNode(void)
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
void Travel_List(Node* list)
{
	// ��nodeָ��node1
	Node* node = list->next;

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
void Insert_Head(Node* list, ElemType element)
{
	// 1.�ڶ��ڴ��д����½ڵ㣬��������������ֵ            
	Node* new_node = (Node*)malloc(sizeof(Node));        
	new_node->data = element; 

	// 2.��ͷ�ڵ��ָ����ֵ���½ڵ�
	new_node->next = list->next;

	// 3.��ͷ�ڵ�ָ���½ڵ�
	list->next = new_node;
}

/** ��ȡβ�ڵ� **/
Node* Get_TailNode(Node* list)
{
	Node* node = list;

	while (node->next != NULL)
	{
		node = node->next;
	}

	return node;
}

/** ����ڵ� -- 2.β�巨 **/
/** ���½ڵ���Ϊ�µ�β�ڵ� **/
void Insert_Tail(Node* list, ElemType element)
{

	// ÿ�ζ�Ҫ��ȡ�����β�ڵ�
	Node* tail_node = Get_TailNode(list);

	// 1.�ڶ��ڴ��д����½ڵ㣬��������������ֵ            
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	// 2.��β�ڵ��ָ����ֵ���½ڵ�
	new_node->next = tail_node->next;

	// 3.��β�ڵ��ָ����ֵ���½ڵ�
	tail_node->next = new_node;

}

/**
			+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+
			| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |
			+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+
				head                node1		           node2		            node3
 pos       ͷ�ڵ㲻�洢����            1                      2	                      3
**/

/** ��ָ��λ�ò���ڵ� **/
void Insert_Node(Node* list, int pos, ElemType element)
{
	// 1.���ҵ�����λ��֮ǰ�Ľڵ�
	Node* node = list;

	for (int i = 0; i < pos - 1; i++) // pos=2
	{
		if (node->next == NULL)
		{
			return;
		}

		node = node->next;
	}

	// 2.�����½ڵ�
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	// 3.���½ڵ������λ��֮ǰ�Ľڵ�ԭ����ָ��Ľڵ�����
	new_node->next = node->next;

	// 4.�ò���λ��֮ǰ�Ľڵ����½ڵ�����
	node->next = new_node;
}


int main(void)
{
	// ��ʼ������(�˿�ֻ��ͷ�ڵ�)
	Node* list = Create_HeadNode();

	Insert_Tail(list, 10);
	Insert_Tail(list, 20);
	Insert_Tail(list, 30);

	Travel_List(list);

	Insert_Node(list, 1, 23);

	printf("\n");
	Travel_List(list);

	return 0;
}