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


// Head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

// pre           curr  
// NULL    Head -> 1 ->  2 -> 3 -> 4 -> 5 -> 6 -> NULL

/** 链表反转 **/
void* Reverse_List(Node* head)
{
	Node* prev = NULL;
	Node* curr = head->next;
	Node* next; // 当curr指向prev时, next用来连接后面的节点

	// 节点移动的顺序
	while (curr != NULL)
	{
		// next保存当前节点的下一个节点，对于单链表，如果不保存，节点改变方向后就找不到旧节点的下一个节点了
		next = curr->next;

		curr->next = prev;

		// 更新prev和curr的位置
		prev = curr;
		curr = next;
	}

	// 让头节点指向prev
	head->next = prev;

}

/** 返回中间节点的前驱节点 **/ 
Node* Find_MidPreNode(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;

	while ((fast != NULL) && (fast->next != NULL))
	{
		// 快指针一次走两步，慢指针一次走一步
		fast = fast->next->next;
		slow = slow->next;
	}

	// 当fast为空或fast->next为空时，slow指向中间节点的前驱节点
	return slow;
}

Node* Find_MidNode(Node* head)
{
	Node* pre_node = Find_MidPreNode(head);

	return pre_node->next;
}

/** 删除中间节点-- 快慢指针 **/
/** 对于偶数个节点，把中间靠后的节点定为中间节点 **/
void Delete_MidNode(Node* head)
{
	Node* pre_node = Find_MidPreNode(head);

	Node* mid_node = pre_node->next;

	// 前驱节点直接指向中间节点的下一个节点
	pre_node->next = mid_node->next;

	// 释放中间节点的内存空间
	free(mid_node);
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

	Delete_MidNode(list);

	Travel_List(list);

	return 0;
}