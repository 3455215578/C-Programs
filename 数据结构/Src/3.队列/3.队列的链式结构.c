#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** 链表结构中的尾指针指向的是有数据的位置 **/

typedef int ElemType;

/** 结构体定义 **/
typedef struct QueueNode
{
	ElemType* data;
	struct QueueNode* next;
}QueueNode;

typedef struct
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

/** 队列初始化 **/
Queue* Init_Queue(void)
{
	// 为队列和头节点开辟堆内存
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));

	head->data = 0;
	head->next = NULL;

	queue->front = head;
	queue->rear = head;

	return queue;
}

/** 判断队列是否为空 **/
bool Queue_Is_Empty(Queue* queue)
{
	if (queue->front == queue->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/** 进队--尾插法 **/
void Enter_Queue(Queue* queue, ElemType element)
{
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->data = element;
	new_node->next = NULL;

	// 尾指针之前指向原来的尾节点(即queue->rear)，现在使原来的尾节点指向新的尾节点
	queue->rear->next = new_node;

	// 再让尾指针指向新的尾节点
	queue->rear = new_node;
}

/** 出队 **/
/** 在链表结构中，出队不移动头节点??? **/
void De_Queue(Queue* queue, ElemType* delete_data)
{
	if (Queue_Is_Empty(queue))
	{
		return;
	}

	QueueNode* delete_node = queue->front->next;
	*delete_data = delete_node->data;

	// queue->front->next原本指向头节点之后的第一个数据节点, 现在该数据节点被删除后，让头节点指向该数据节点的下一次节点
	queue->front->next = delete_node->next;

	// 如果被删除的节点为队列的尾指针所指向的节点，则让尾指针和头指针一起指向头节点
	if (delete_node == queue->rear)
	{
		queue->rear = queue->front;
	}

	free(delete_node);
}

ElemType Get_Top(Queue* queue)
{
	if (Queue_Is_Empty(queue))
	{
		return;
	}

	return queue->front->next->data;
}

int main(void)
{
	Queue* queue = Init_Queue();

	Enter_Queue(queue, 10);
	Enter_Queue(queue, 20);
	Enter_Queue(queue, 30);
	Enter_Queue(queue, 40);
	Enter_Queue(queue, 50);

	ElemType delete_data;
	De_Queue(queue, &delete_data);
	printf("出队%d\n", delete_data);
	De_Queue(queue, &delete_data);
	printf("出队%d\n", delete_data);

	ElemType top_data = Get_Top(queue);
	printf("队头%d\n", top_data);

	return 0;
}