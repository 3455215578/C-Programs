#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

/** ǰ������ **/
typedef struct node
{
	ElemType data;
	struct node* next; // �ڽṹ�嶨�屻���֮ǰ����������֪�� Node ��һ�����ͱ���
	// nextָ����ǽڵ�
}Node;

/** ����ֻ��ͷ�ڵ������ **/
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

/** ����ڵ� -- 2.β�巨 **/
/** ���½ڵ���Ϊ�µ�β�ڵ� **/
void Insert_Tail(Node* head, ElemType element)
{

	// ÿ�ζ�Ҫ��ȡ�����β�ڵ�
	Node* tail_node = Get_TailNode(head);

	// 1.�ڶ��ڴ��д����½ڵ㣬��������������ֵ            
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	// 2.��β�ڵ��ָ����ֵ���½ڵ�
	new_node->next = tail_node->next;

	// 3.��β�ڵ��ָ����ֵ���½ڵ�
	tail_node->next = new_node;

}

/**
		+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+	    +��������������������������������+
		| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |	    | element | NULL |
		+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+	    +��������������������������������+
			head                node1		           node2		            node3		           node4


		Node* p = head->next;
		Node* q;

��һ�Σ�
		if(p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}


		+����������������������+   	pq +��������������������������������+	     +��������������������������������+		  +��������������������������������+
		| 0 | node1 |   	   | element | next |	     | element | next |		  | element | NULL |
		+����������������������+   	   +��������������������������������+	     +��������������������������������+		  +��������������������������������+
			head                     node2		               node3		             node4


�ڶ��Σ�
		if(p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}

		+����������������������+     pq +��������������������������������+		  +��������������������������������+
		| 0 | node1 |        | element | next |		  | element | NULL |
		+����������������������+        +��������������������������������+		  +��������������������������������+
			head                     node3		             node4


�����Σ�
		if(p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}

		+����������������������+     pq +��������������������������������+
		| 0 | node1 |        | element | NULL |
		+����������������������+        +��������������������������������+
			head                     node4

���ĴΣ�
		if(p == NULL)
		{
			free(p);
		}

		+����������������������+
		| 0 | node1 |
		+����������������������+
			head

**/

/** �ͷ����� **/
/** ֻ����ͷ�ڵ� **/
void Free_List(Node* head)
{
	Node* p = head;
	Node* q;

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}

	head->next = NULL;
}

/** Ѱ��β�ڵ� **/
Node* Find_EndNode(Node* head)
{
	Node* node = head;

	while (node->next != NULL)
	{
		node = node->next;
	}

	return node;
}

/**
���ϣ�������ܹ��޸Ĵ���ָ����ָ���ֵ������Ҫʹ��ָ���ָ�루Node**����Ϊ������
��ǰ�ĺ���ʹ�� Node* ���͵Ĳ���������ζ�� encounter_node �ǰ�ֵ���ݵģ������ڲ����κ��޸Ķ����ᷴӳ��ԭʼ�����ϡ�
**/

/** �ж������Ƿ��л� **/
/** ���У��򷵻�����ʱ�Ľڵ� **/
bool Is_Circle(Node* head, Node** encounter_node)
{
	// ����ָ��
	Node* fast = head;
	Node* slow = head;

	while ((fast != NULL) && (fast->next != NULL))
	{
		// ȷ��fast->next��Ϊ�գ��������ִ���
		fast = (fast->next)->next;
		slow = slow->next;

		// ���ж�
		if (fast == slow)
		{
			*encounter_node = slow;
			return true;
		}
	}

	return false;
}

/**
��һ��ָ���������ʼλ�ÿ�ʼ��������ͬʱ��һ��ָ����л�ʱ�������λ�ÿ�ʼ�ƻ����У�
����ָ�붼��ÿ�ξ���һ�������վ�һ�������뻷��������
**/

/** Ѱ��ѭ��������뻷�ڵ� **/
Node* Find_EnterNode(Node* head)
{
	Node* encounter_node;
	bool is_circle = Is_Circle(head, &encounter_node);

	if (is_circle)
	{
		Node* fast = head;
		Node* slow = encounter_node;

		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return fast;
	}
	else
	{
		printf("����û��\n");
		return;
	}
}

int main(void)
{
	// ����ͷ�ڵ�
	Node* list = Create_HeadNode();

	// ����Ԫ��
	Insert_Tail(list, 1);
	Insert_Tail(list, 2);
	Insert_Tail(list, 3);
	Node* enter_node = Get_TailNode(list);
	Insert_Tail(list, 4);
	Insert_Tail(list, 5);
	Insert_Tail(list, 6);
	Insert_Tail(list, 7);
	Insert_Tail(list, 8);
	Node* end_node = Get_TailNode(list);

	// β�ڵ�ָ��ͷ�ڵ�
	end_node->next = enter_node;

	enter_node = Find_EnterNode(list);

	printf("%d\n", enter_node->data);

	return 0;
}