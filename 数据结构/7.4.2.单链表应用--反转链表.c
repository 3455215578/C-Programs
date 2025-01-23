#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** 前向声明 **/
typedef struct node
{
	ElemType data;
	struct node* next;
}Node;

/** 创建只有头节点的链表 **/
Node* Create_HeadNode(void)
{
	Node* head = (Node*)malloc(sizeof(Node));

	head->data = 0;

	head->next = NULL;

	return head;
}


/** 遍历链表 **/
void Travel_List(Node* head)
{
	// 让node指向node1
	Node* node = head->next;

	while (node != NULL)
	{
		printf("%d\n", node->data);

		node = node->next;
	}

	printf("\n");
}

/** 获取尾节点 **/
Node* Get_TailNode(Node* head)
{
	Node* node = head;

	while (node->next != NULL)
	{
		node = node->next;
	}

	return node;
}

/** 尾插法 **/

void Insert_Tail(Node* head, ElemType element)
{
	Node* tail_node = Get_TailNode(head);

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	new_node->next = tail_node->next;

	tail_node->next = new_node;

}


/** 获取链表长度 **/
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
	first = Create_HeadNote();
	second = head->next;
	third = second->next;

	Node* node = second;

	(fir)         (sec)   (thi)
	NULL  Head ->   1   ->  2  -> 3 -> 4 -> 5 -> 6 -> NULL 
	             (node)
**/

/**

 第一次:
①让second指向fir: sec->next = fir;



②：更新fir,sec,thi的位置为下：
							fir = node;
							sec = node->next;
							thi = sec->next;

③更新node: node = node->next;

//	       fir  sec  thi
//  NULL <- 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
               (node)

**/



/**

 第二次:
①让second指向fir: 

②：更新fir,sec,thi的位置:

**/



/** 链表反转 **/
void Reverse_List(Node* head)
{
	Node* first;
	Node* second;
	Node* third;

	first = Create_HeadNode();
	second = head->next;
	third = second->next;

	Node* node = second;

	while (second != NULL)
	{
		// 让sec指向fir
		second->next = first;

		// 更新fir、sec、thi的位置
		first = node;
		second = node->next;
		third = second->next;

		// 更新node
		node = node->next;

	}

	second = Create_HeadNode();
	second->next = first;

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