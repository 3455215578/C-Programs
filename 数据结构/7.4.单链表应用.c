#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** 声明结构体 **/
typedef struct node
{
	ElemType data;
	struct node* link;

}Node;

/** 创建只有头节点的链表 **/
Node* Create_HeadNode(void)
{
	Node* head = (Node*)malloc(sizeof(Node));

	head->data = 0;

	head->link = NULL;

	return head;
}

/** 遍历链表 **/
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


/** 头插法 **/
void Insert_Head(Node* head, ElemType element)
{           
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	new_node->link = head->link;

	head->link = new_node;
}

/** 获取链表长度 **/
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
	+———————————+    +—————————————————+	 +————————————————+	     +————————————————+	    +————————————————+
	| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |	    | element | NULL |
	+———————————+    +—————————————————+	 +————————————————+	     +————————————————+	    +————————————————+
		head                node1		           node2		            node3		           node4
		  0                   1                      2                        3                     4
**/

/** 寻找倒数第k个节点--两次循环 **/
Node* Find_BackNode(Node* head, int k)
{
	// 1.遍历，获取链表长度
	int length = Get_Length(head);

	// 2.获取倒数第k个节点对应的位置
	int pos = length - k;

	// 3.再遍历，返回该节点
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
	+———————————+    +—————————————————+	 +————————————————+	     +————————————————+	    +————————————————+
	| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |	    | element | NULL |
	+———————————+    +—————————————————+	 +————————————————+	     +————————————————+	    +————————————————+
		head                node1		           node2		            node3		           node4
		  0                   1                      2                        3                     4
**/


/** 寻找倒数第k个节点--快慢指针法 **/
Node* Find_BackNode_Double_Point(Node* head, int k)
{
	// 1.先让快慢指针都指向第一个节点
	Node* fast = head->link;
	Node* slow = head->link;

	// 2. 再让快指针走k步(0 ~ k-1)
	for (int i = 0; i < k; i++)
	{
		fast = fast->link;
	}

	// 3.最后让快慢指针同时移动, 当快指针指向NULL时，慢指针指向的就是指定位置
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