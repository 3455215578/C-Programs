#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** 前向声明 **/
typedef struct node
{
	ElemType data;
	struct node *prev, *next; // 在结构体定义被完成之前，编译器不知道 Node 是一个类型别名
	// next指向的是节点
}Node;

/** 创建头节点 **/
Node* Create_HeadNode(void)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

/** 头插法 **/
void Insert_Head(Node* head, ElemType element)
{
	Node* node = (Node*)malloc(sizeof(Node));

	// 数据域赋值
	node->data = element;

	// 新节点的prev和next指向
	node->prev = head;
	node->next = head->next;

	// 原节点指向
	if (head->next != NULL)
	{
		head->next->prev = node;
	}

	head->next = node;
}

/** 遍历链表 **/
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

void Insert_Tail(Node* head, ElemType element)
{
	// 寻找尾节点
	Node* tail_node = Get_TailNode(head);

	// 创建新节点并赋值
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;

	// 指向
	node->prev = tail_node;
	node->next = NULL;
	tail_node->next = node;
}

/** 寻找指定位置的前驱节点 **/
Node* Find_PreNode(Node* head, int pos)
{
	if (pos == 0)
	{
		printf("头节点没有前驱节点\n");
		return;
	}

	Node* node = head;

	for (int i = 0; i < pos - 1; i++) // pos=2
	{
		if (node->next == NULL)
		{
			return;
		}

		node = node->next;

	}

	return node;
}

/** 在指定位置插入节点 **/
void Insert_Node(Node* head, int pos, ElemType element)
{
	// 寻找前驱节点
	Node* pre_node = Find_PreNode(head, pos);

	// 创建新节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;

	// 指向
	node->prev = pre_node;
	node->next = pre_node->next;

	if (pre_node->next != NULL)
	{
		pre_node->next->prev = node;
	}

	pre_node->next = node;

}

/** 删除指定位置的节点, 并返回被删除节点存储的数据 **/
void Delete_Node(Node* head, int pos, ElemType* delete_data)
{
	// 找到被删除节点的前驱节点
	Node* pre_node = Find_PreNode(head, pos);

	if (pre_node->next == NULL)
	{
		printf("要删除的节点不存在\n");
		return;
	}

	Node* delete_node = pre_node->next;

	// 保存被删除节点的数据
	*delete_data = delete_node->data;

	pre_node->next = delete_node->next;

	free(delete_node);

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

	ElemType delete_data;

	Delete_Node(list, 6, &delete_data);

	Travel_List(list);
	printf("%d\n", delete_data);

	return 0;
}