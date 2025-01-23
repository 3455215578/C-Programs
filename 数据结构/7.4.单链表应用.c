#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** �����ṹ�� **/
typedef struct node
{
	ElemType data;
	struct node* link;

}Node;

/** ����ֻ��ͷ�ڵ������ **/
Node* Create_HeadNode(void)
{
	Node* head = (Node*)malloc(sizeof(Node));

	head->data = 0;

	head->link = NULL;

	return head;
}

/** �������� **/
void Travel_List(Node* head)
{
	Node* node = head->link;

	while (node != NULL)
	{
		printf("%d\n", node->data);

		node = node->link;
	}

	printf("\n");
}


/** ͷ�巨 **/
void Insert_Head(Node* head, ElemType element)
{           
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	new_node->link = head->link;

	head->link = new_node;
}

/** ��ȡ������ **/
int Get_Length(Node* head)
{
	Node* node = head;
	int length = 0;

	while (node != NULL)
	{
		length++;
		node = node->link;
	}

	return length;
}



/**
	+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+	    +��������������������������������+
	| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |	    | element | NULL |
	+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+	    +��������������������������������+
		head                node1		           node2		            node3		           node4
		  0                   1                      2                        3                     4
**/

/** Ѱ�ҵ�����k���ڵ�--����ѭ�� **/
Node* Find_BackNode(Node* head, int k)
{
	// 1.��������ȡ������
	int length = Get_Length(head);

	// 2.��ȡ������k���ڵ��Ӧ��λ��
	int pos = length - k;

	// 3.�ٱ��������ظýڵ�
	Node* node = head;

	for (int i = 0; i < pos; i++)
	{
		node = node->link;
	}

	return node;
}

/**
					  fast
					  slow
	+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+	    +��������������������������������+
	| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |	    | element | NULL |
	+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+	    +��������������������������������+
		head                node1		           node2		            node3		           node4
		  0                   1                      2                        3                     4
**/


/** Ѱ�ҵ�����k���ڵ�--����ָ�뷨 **/
Node* Find_BackNode_Double_Point(Node* head, int k)
{
	// 1.���ÿ���ָ�붼ָ���һ���ڵ�
	Node* fast = head->link;
	Node* slow = head->link;

	// 2. ���ÿ�ָ����k��(0 ~ k-1)
	for (int i = 0; i < k; i++)
	{
		fast = fast->link;
	}

	// 3.����ÿ���ָ��ͬʱ�ƶ�, ����ָ��ָ��NULLʱ����ָ��ָ��ľ���ָ��λ��
	while (fast != NULL)
	{
		fast = fast->link;
		slow = slow->link;
	}

	return slow;
}

int main(void)
{
	Node* list = Create_HeadNode();

	Insert_Head(list, 50);
	Insert_Head(list, 40);
	Insert_Head(list, 30);
	Insert_Head(list, 20);
	Insert_Head(list, 10);

	Travel_List(list);

	Node* node = Find_BackNode(list, 1);
	printf("%d\n", node->data);

	return 0;
}