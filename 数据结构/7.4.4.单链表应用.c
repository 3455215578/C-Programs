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

/** 尾插法 **/
void Insert_Tail(Node* head, ElemType element)
{
	Node* tail_node = Get_TailNode(head);

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	new_node->next = tail_node->next;

	tail_node->next = new_node;

}

/** 寻找指定位置的前驱节点 **/
Node* Find_PreNode(Node* head, int pos)
{
	if (pos == 0)
	{
		printf("头节点没有前驱节点\n");
	}
	else
	{
		Node* node = head;

		for (int i = 0; i < pos - 1; i++)
		{
			if (node->next == NULL)
			{
				return;
			}

			node = node->next;
		}

		return node;
	}
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

//Init: Head 1 2 3 4 5 6 NULL
//End:  Head 1 6 2 5 3 4 NULL

// Head 1 2 3 NULL
// Head 4 5 6 NULL

// Head 1 2 3 NULL
// Head 6 5 4 NULL
int main(void)
{
	Node* list = Create_HeadNode();

	Insert_Tail(list, 1);
	Insert_Tail(list, 2);
	Insert_Tail(list, 3);
	Insert_Tail(list, 4);
	Insert_Tail(list, 5);
	Insert_Tail(list, 6);

	// 1.将原链表中的中间节点及以后的节点移动到新链表
	Node* new_list = Create_HeadNode();

	Node* pre_node = Find_MidPreNode(list);
	Node* temp1 = pre_node->next;

	while (temp1 != NULL)
	{
		Insert_Tail(new_list, temp1->data);
		temp1 = temp1->next;
	}

	pre_node->next = NULL;

	// 2.将新链表反转
	Reverse_List(new_list);

	// 3.将新链表的节点间隔插入到原链表

	temp1 = list->next;
	Node* temp2 = new_list->next;

	// 保存原链表和新链表的节点
	Node *temp_node1, *temp_node2;
	while ((temp1 != NULL) && (temp2 != NULL))
	{
		temp_node1 = temp1;
		temp_node2 = temp2;

		temp2->next = temp_node1->next;
		temp1->next = temp2;


	}


	return 0;
}