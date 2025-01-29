#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** 先进先出 **/
/** 顺序结构中的尾指针指向的是没有数据的空位 **/

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
	ElemType* data;
	// 队头
	int front;
	// 队尾
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

/** 出队 **/
void De_Queue(Queue* queue, ElemType* delete_data)
{
	if (Queue_Is_Empty(queue))
	{
		return;
	}

	*delete_data = queue->data[queue->front];
	queue->front++;
}

/** 判断队列是否真满了，若没满则调整队列 **/
bool Queue_Is_Full(Queue* queue)
{
	if (queue->front > 0)
	{
		int step = queue->front;

		// 时间复杂度比较高
		for (int i = queue->front; i <= queue->rear; i++)
		{
			queue->data[i - step] = queue->data[i];
		}

		queue->front = 0;
		queue->rear = queue->rear - step;

		// 队列没完全满
		return false;
	}
	else
	{
		// 真满了
		return true;
	}
}

/** 入队 **/
void Enter_Queue(Queue* queue, ElemType element)
{
	if (queue->rear >= MAXSIZE) // rear指向的是空位
	{
		if (Queue_Is_Full(queue))
		{
			return;
		}
	}

	queue->data[queue->rear] = element;
	queue->rear++;
}

void Travel_Queue(Queue* queue)
{
	for (int i = queue->front; i < queue->rear; i++)
	{
		printf("%d\n", queue->data[i]);
	}
}

/** 获取队头数据 **/
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

	Enter_Queue(queue, 10);
	Enter_Queue(queue, 20);
	Enter_Queue(queue, 30);
	Enter_Queue(queue, 40);
	Enter_Queue(queue, 50);

	ElemType delete_data;
	De_Queue(queue, &delete_data);
	printf("%d\n", delete_data);
	De_Queue(queue, &delete_data);
	printf("%d\n", delete_data);

	ElemType head_data = Get_Head(queue);
	printf("%d\n", head_data);

	return 0;
}