#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** ����ṹ�е�βָ��ָ����������ݵ�λ�� **/

typedef int ElemType;

/** �ṹ�嶨�� **/
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

/** ���г�ʼ�� **/
Queue* Init_Queue(void)
{
	// Ϊ���к�ͷ�ڵ㿪�ٶ��ڴ�
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));

	head->data = 0;
	head->next = NULL;

	queue->front = head;
	queue->rear = head;

	return queue;
}

/** �ж϶����Ƿ�Ϊ�� **/
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

/** ����--β�巨 **/
void Enter_Queue(Queue* queue, ElemType element)
{
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->data = element;
	new_node->next = NULL;

	// βָ��֮ǰָ��ԭ����β�ڵ�(��queue->rear)������ʹԭ����β�ڵ�ָ���µ�β�ڵ�
	queue->rear->next = new_node;

	// ����βָ��ָ���µ�β�ڵ�
	queue->rear = new_node;
}

/** ���� **/
/** ������ṹ�У����Ӳ��ƶ�ͷ�ڵ�??? **/
void De_Queue(Queue* queue, ElemType* delete_data)
{
	if (Queue_Is_Empty(queue))
	{
		return;
	}

	QueueNode* delete_node = queue->front->next;
	*delete_data = delete_node->data;

	// queue->front->nextԭ��ָ��ͷ�ڵ�֮��ĵ�һ�����ݽڵ�, ���ڸ����ݽڵ㱻ɾ������ͷ�ڵ�ָ������ݽڵ����һ�νڵ�
	queue->front->next = delete_node->next;

	// �����ɾ���Ľڵ�Ϊ���е�βָ����ָ��Ľڵ㣬����βָ���ͷָ��һ��ָ��ͷ�ڵ�
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
	printf("����%d\n", delete_data);
	De_Queue(queue, &delete_data);
	printf("����%d\n", delete_data);

	ElemType top_data = Get_Top(queue);
	printf("��ͷ%d\n", top_data);

	return 0;
}