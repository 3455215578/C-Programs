#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/** ǰ������ **/
typedef struct node
{
	ElemType data;
	struct node* next;
}Node;

/** ����ֻ��ͷ�ڵ������ **/
Node* Create_HeadNode(void)
{
	Node* head = (Node*)malloc(sizeof(Node));

	head->data = 0;

	head->next = NULL;

	return head;
}


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

/** β�巨 **/
void Insert_Tail(Node* head, ElemType element)
{
	Node* tail_node = Get_TailNode(head);

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = element;

	new_node->next = tail_node->next;

	tail_node->next = new_node;

}

/** Ѱ��ָ��λ�õ�ǰ���ڵ� **/
Node* Find_PreNode(Node* head, int pos)
{
	if (pos == 0)
	{
		printf("ͷ�ڵ�û��ǰ���ڵ�\n");
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

/** ����ת **/
void* Reverse_List(Node* head)
{
	Node* prev = NULL;
	Node* curr = head->next;
	Node* next; // ��currָ��prevʱ, next�������Ӻ���Ľڵ�

	// �ڵ��ƶ���˳��
	while (curr != NULL)
	{
		// next���浱ǰ�ڵ����һ���ڵ㣬���ڵ�������������棬�ڵ�ı䷽�����Ҳ����ɽڵ����һ���ڵ���
		next = curr->next;

		curr->next = prev;

		// ����prev��curr��λ��
		prev = curr;
		curr = next;
	}

	// ��ͷ�ڵ�ָ��prev
	head->next = prev;

}

/** �����м�ڵ��ǰ���ڵ� **/
Node* Find_MidPreNode(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;

	while ((fast != NULL) && (fast->next != NULL))
	{
		// ��ָ��һ������������ָ��һ����һ��
		fast = fast->next->next;
		slow = slow->next;
	}

	// ��fastΪ�ջ�fast->nextΪ��ʱ��slowָ���м�ڵ��ǰ���ڵ�
	return slow;
}

Node* Find_MidNode(Node* head)
{
	Node* pre_node = Find_MidPreNode(head);

	return pre_node->next;
}

/** ɾ���м�ڵ�-- ����ָ�� **/
/** ����ż�����ڵ㣬���м俿��Ľڵ㶨Ϊ�м�ڵ� **/
void Delete_MidNode(Node* head)
{
	Node* pre_node = Find_MidPreNode(head);

	Node* mid_node = pre_node->next;

	// ǰ���ڵ�ֱ��ָ���м�ڵ����һ���ڵ�
	pre_node->next = mid_node->next;

	// �ͷ��м�ڵ���ڴ�ռ�
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

	// 1.��ԭ�����е��м�ڵ㼰�Ժ�Ľڵ��ƶ���������
	Node* new_list = Create_HeadNode();

	Node* pre_node = Find_MidPreNode(list);
	Node* temp1 = pre_node->next;

	while (temp1 != NULL)
	{
		Insert_Tail(new_list, temp1->data);
		temp1 = temp1->next;
	}

	pre_node->next = NULL;

	// 2.��������ת
	Reverse_List(new_list);

	// 3.��������Ľڵ������뵽ԭ����

	temp1 = list->next;
	Node* temp2 = new_list->next;

	// ����ԭ�����������Ľڵ�
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