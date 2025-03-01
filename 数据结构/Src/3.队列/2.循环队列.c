#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** �Ƚ��ȳ� **/

#define MAXSIZE 5

typedef int ElemType;

typedef struct
{
	ElemType* data;
	// ��ͷ
	int front;
	// ��β
	int rear;


}Queue;

Queue* Init_Queue(void)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	queue->front = 0;
	queue->rear = 0;

	return queue;
}

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

/** ���� **/
void De_Queue(Queue* queue, ElemType* delete_data)
{
	if (Queue_Is_Empty(queue))
	{
		return;
	}

	*delete_data = queue->data[queue->front];
	queue->front = (queue->front + 1) % MAXSIZE;

}

/** �ж϶����Ƿ������� **/
bool Queue_Is_Full(Queue* queue)
{
	if (((queue->rear + 1) % MAXSIZE == queue->front))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

/** ��� **/
void Enter_Queue(Queue* queue, ElemType element)
{
	if (Queue_Is_Full(queue))
	{
		printf("����������\n");
		return;
	}

	queue->data[queue->rear] = element;
	queue->rear = (queue->rear + 1) % MAXSIZE;

}

void Travel_Queue(Queue* queue)
{
	for (int i = queue->front; i < queue->rear; i++)
	{
		printf("%d\n", queue->data[i]);
	}
}

/** ��ȡ��ͷ���� **/
ElemType Get_Head(Queue* queue)
{
	if (Queue_Is_Empty(queue))
	{
		return;
	}

	return queue->data[queue->front];
}

int main(void)
{
	Queue* queue = Init_Queue();

	Enter_Queue(queue, 1);
	Enter_Queue(queue, 2);
	Enter_Queue(queue, 3);
	Enter_Queue(queue, 4);
	Enter_Queue(queue, 5);

	Travel_Queue(queue);

	return 0;
}