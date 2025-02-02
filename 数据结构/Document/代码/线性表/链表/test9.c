#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node *next;
}Node;

//初化链表
Node* initList()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//头插法
int insertHead(Node* L, ElemType e)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}

//遍历
void listNode(Node* L)
{
	Node *p = L->next;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//获取尾部结点
Node*  get_tail(Node  *L)
{
	Node *p = L;
	while(p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

//尾插法
Node* insertTail(Node *tail, ElemType e)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}

//指定位置插入
int insertNode(Node *L, int pos, ElemType e)
{
	Node *p = L;
	int i = 0;
	while(i < pos-1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}
	

	Node *q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}

//删除节点
int deleteNode(Node *L, int pos)
{
	Node *p = L;
	int i = 0;
	while(i < pos-1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}

	if(p->next == NULL)
	{
		printf("要删除的位置错误\n");
		return 0;
	}

	Node *q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

//获取链表长度
int listLength(Node *L)
{
	Node *p = L;
	int len = 0;
	while(p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

//释放链表
void freeList(Node *L)
{
	Node *p = L->next;
	Node *q;

	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

//查找倒数第k个节点
int findNodeFS(Node *L, int k)
{
	Node *fast = L->next;
	Node *slow = L->next;

	for (int i = 0; i < k; i++)
	{
		fast = fast->next;
	}

	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	printf("倒数第%d个节点值为：%d\n", k, slow->data);
	return 1;
}

int main(int argc, char const *argv[])
{
	Node *list = initList();
	Node *tail = get_tail(list);
	tail  = insertTail(tail, 10);
	tail  = insertTail(tail, 20);
	tail  = insertTail(tail, 30);
	tail  = insertTail(tail, 40);
	tail  = insertTail(tail, 50);
	tail  = insertTail(tail, 60);
	tail  = insertTail(tail, 70);
	listNode(list);
	findNodeFS(list, 3);
	return 0;
}






