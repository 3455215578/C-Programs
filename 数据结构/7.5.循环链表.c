#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

/** 前向声明 **/
typedef struct node
{
	ElemType data;
	struct node* next; // 在结构体定义被完成之前，编译器不知道 Node 是一个类型别名
	// next指向的是节点
}Node;

/** 创建只有头节点的链表 **/
Node* Create_HeadNode(void)
{
	// 定义头节点
	//  data: 0;
	//  next: NULL
	Node* head = (Node*)malloc(sizeof(Node));

	head->data = 0;

	head->next = NULL;

	return head;
}

/**

	+———————————+    +—————————————————+	 +————————————————+
	| 0 | node1 |    | element | node2 |	 | element | next |
	+———————————+    +—————————————————+	 +————————————————+
		head              node1		              node2

**/


/** 遍历链表 **/
/** 哑节点：添加在链表头部，不存储数据的节点 **/
/** 在包含哑节点的链表中，"头节点"指的是这个哑节点本身，而"第一个节点"则是指哑节点之后的第一个实际数据节点。 **/
void Travel_List(Node* head)
{
	// 让node指向node1
	Node* node = head->next;

	while (node != NULL)
	{
		printf("%d\n", node->data);

		// 更新node
		node = node->next; // 因为node1的指针域指向node2, 所以让node指向node1的指针域, 即node指向node2
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

/** 插入节点 -- 2.尾插法 **/
/** 把新节点作为新的尾节点 **/
void Insert_Tail(Node* head, ElemType element)
{

	// 每次都要获取链表的尾节点
	Node* tail_node = Get_TailNode(head);

	// 1.在堆内存中创建新节点，并给它的数据域赋值            
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	// 2.把尾节点的指针域赋值给新节点
	new_node->next = tail_node->next;

	// 3.把尾节点的指针域赋值给新节点
	tail_node->next = new_node;

}

/**
		+———————————+    +—————————————————+	 +————————————————+	     +————————————————+	    +————————————————+
		| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |	    | element | NULL |
		+———————————+    +—————————————————+	 +————————————————+	     +————————————————+	    +————————————————+
			head                node1		           node2		            node3		           node4


		Node* p = head->next;
		Node* q;

第一次：
		if(p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}


		+———————————+   	pq +————————————————+	     +————————————————+		  +————————————————+
		| 0 | node1 |   	   | element | next |	     | element | next |		  | element | NULL |
		+———————————+   	   +————————————————+	     +————————————————+		  +————————————————+
			head                     node2		               node3		             node4


第二次：
		if(p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}

		+———————————+     pq +————————————————+		  +————————————————+
		| 0 | node1 |        | element | next |		  | element | NULL |
		+———————————+        +————————————————+		  +————————————————+
			head                     node3		             node4


第三次：
		if(p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}

		+———————————+     pq +————————————————+
		| 0 | node1 |        | element | NULL |
		+———————————+        +————————————————+
			head                     node4

第四次：
		if(p == NULL)
		{
			free(p);
		}

		+———————————+
		| 0 | node1 |
		+———————————+
			head

**/

/** 释放链表 **/
/** 只保留头节点 **/
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

/** 寻找尾节点 **/
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
如果希望函数能够修改传入指针所指向的值，您需要使用指针的指针（Node**）作为参数。
当前的函数使用 Node* 类型的参数，这意味着 encounter_node 是按值传递的，函数内部的任何修改都不会反映到原始变量上。
**/

/** 判断链表是否有环 **/
/** 若有，则返回相遇时的节点 **/
bool Is_Circle(Node* head, Node** encounter_node)
{
	// 快慢指针
	Node* fast = head;
	Node* slow = head;

	while ((fast != NULL) && (fast->next != NULL))
	{
		// 确保fast->next不为空，否则会出现错误
		fast = (fast->next)->next;
		slow = slow->next;

		// 环判断
		if (fast == slow)
		{
			*encounter_node = slow;
			return true;
		}
	}

	return false;
}

/**
让一个指针从链表起始位置开始遍历链表，同时让一个指针从判环时相遇点的位置开始绕环运行，
两个指针都是每次均走一步，最终就一定会在入环点相遇。
**/

/** 寻找循环链表的入环节点 **/
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
		printf("链表没环\n");
		return;
	}
}

int main(void)
{
	// 创建头节点
	Node* list = Create_HeadNode();

	// 插入元素
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

	// 尾节点指向头节点
	end_node->next = enter_node;

	enter_node = Find_EnterNode(list);

	printf("%d\n", enter_node->data);

	return 0;
}