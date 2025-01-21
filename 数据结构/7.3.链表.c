#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** 前向声明 **/
typedef struct node
{
	ElemType data;
	struct node* next; // 在结构体定义被完成之前，编译器不知道 Node 是一个类型别名
}Node;

Node* Init_Node(void)
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
void Travel_Node(Node* head)
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

/**

// 原来的头节点
				+——————————+
	head     :  | 0 | NULL |
				+——————————+


// 1.创建新节点，并给数据域赋值
				+————————————————+
	new_node : 	| element |      |
				+————————————————+


// 2.将原来头节点的指针域赋值给新节点的指针域
				+——————————+
	head     :  | 0 | NULL |
				+——————————+

				+————————————————+
	new_node : 	| element | NULL |
				+————————————————+

// 3.将原来头节点的指针域指向新节点
				+——————————————+
	head     :  | 0 | new_node |
				+——————————————+

				+————————————————+
	new_node : 	| element | NULL |
				+————————————————+

**/


/** 插入节点 -- 1.头插法 **/
/** 每次都在头节点之后插入新节点 **/
void Insert_Head(Node* head, ElemType element)
{
	// 1.在堆内存中创建新节点，并给它的数据域赋值            
	Node* new_node = (Node*)malloc(sizeof(Node));        
	new_node->data = element; 

	// 2.把头节点的指针域赋值给新节点
	new_node->next = head->next;

	// 3.让头节点指向新节点
	head->next = new_node;
}

/** 获取尾节点 **/
Node* Get_TailNode(Node* head)
{
	Node* node = head->next;
	while (node != NULL)
	{
		node = node->next;
	}

	return node;
}

/** 插入节点 -- 2.尾插法 **/
/** 把新节点作为新的尾节点 **/
void Insert_Tail(Node* tail, ElemType element)
{
	// 1.在堆内存中创建新节点，并给它的数据域赋值            
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;



	// 2.把尾节点的指针域赋值给新节点
	new_node->next = NULL;



}

int main(void)
{
	// 初始化链表(此刻只有头节点)
	Node* list = Init_Node();

	Insert_Head(list, 10);
	Insert_Head(list, 20);
	Insert_Head(list, 30);

	Travel_Node(list);

	return 0;
}