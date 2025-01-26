#include <stdio.h>
#include <stdlib.h>

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
		+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+
		| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |
		+����������������������+    +����������������������������������+	 +��������������������������������+	     +��������������������������������+
			head                node1		           node2		            node3
 pos         0                    1                      2	                      3
**/

/** Ѱ��ָ��λ�õ�ǰ���ڵ� **/
Node* Find_PreNode(Node* head, int pos)
{
	if (pos == 0)
	{
		printf("ͷ�ڵ�û��ǰ���ڵ�\n");
		return NULL;
	}

	Node* node = head;

	for (int i = 0; i < pos - 1; i++) // pos=2
	{
		if (node->next == NULL)
		{
			return NULL;
		}

		node = node->next;

	}

	return node;
}

/** ��ָ��λ�ò���ڵ� **/
void Insert_Node(Node* head, int pos, ElemType element)
{
	// 1.���ҵ�����λ�õ�ǰ���ڵ�
	Node* pre_node = Find_PreNode(head, pos);

	// 2.�����½ڵ�
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	// 3.���½ڵ���ǰ���ڵ�ԭ����ָ��Ľڵ�����
	new_node->next = pre_node->next;

	// 4.��ǰ���ڵ����½ڵ�����
	pre_node->next = new_node;

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

// Head 10 20 NULL
/** ɾ��ָ��λ�õĽڵ㲢���ظýڵ�洢�����ݣ�ͬʱ�ͷŸýڵ���ڴ�ռ� **/
void Delete_Node(Node* head, int pos, ElemType* delete_data)
{
	// 1. ���ҵ�ɾ��λ�õ�ǰ���ڵ�
	Node* pre_node = Find_PreNode(head, pos);

	if ((pre_node == NULL) || (pre_node->next == NULL))
	{
		printf("ɾ��λ�ô���\n");
		return NULL;
	}

	// 2. ���汻ɾ���Ľڵ㲢�洢�ڵ��е�����
	Node* delete_node = pre_node->next;
	*delete_data = delete_node->data;

	// 3.ָ��
	pre_node->next = delete_node->next;
	
	// 4.�ͷű�ɾ���ڵ���ڴ�ռ�
	free(delete_node);
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

int main(void)
{
	Node* list = Create_HeadNode();

	Insert_Head(list, 20);
	Insert_Head(list, 10);

	ElemType delete_data;

	Travel_List(list);

	Delete_Node(list, 1, &delete_data);

	Travel_List(list);

	return 0;
}