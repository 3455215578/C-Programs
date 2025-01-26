#include <stdio.h>
#include <stdlib.h>

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
		+———————————+    +—————————————————+	 +————————————————+	     +————————————————+
		| 0 | node1 |    | element | node2 |	 | element | next |	     | element | next |
		+———————————+    +—————————————————+	 +————————————————+	     +————————————————+
			head                node1		           node2		            node3
 pos         0                    1                      2	                      3
**/

/** 寻找指定位置的前驱节点 **/
Node* Find_PreNode(Node* head, int pos)
{
	if (pos == 0)
	{
		printf("头节点没有前驱节点\n");
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

/** 在指定位置插入节点 **/
void Insert_Node(Node* head, int pos, ElemType element)
{
	// 1.先找到插入位置的前驱节点
	Node* pre_node = Find_PreNode(head, pos);

	// 2.创建新节点
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	// 3.让新节点与前驱节点原来所指向的节点相连
	new_node->next = pre_node->next;

	// 4.让前驱节点与新节点相连
	pre_node->next = new_node;

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

// Head 10 20 NULL
/** 删除指定位置的节点并返回该节点存储的数据，同时释放该节点的内存空间 **/
void Delete_Node(Node* head, int pos, ElemType* delete_data)
{
	// 1. 先找到删除位置的前驱节点
	Node* pre_node = Find_PreNode(head, pos);

	if ((pre_node == NULL) || (pre_node->next == NULL))
	{
		printf("删除位置错误\n");
		return NULL;
	}

	// 2. 保存被删除的节点并存储节点中的数据
	Node* delete_node = pre_node->next;
	*delete_data = delete_node->data;

	// 3.指向
	pre_node->next = delete_node->next;
	
	// 4.释放被删除节点的内存空间
	free(delete_node);
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