#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** �Ƚ��ȳ� **/
/** ˳��ṹ�е�βָ��ָ�����û�����ݵĿ�λ **/

#define MAXSIZE 100

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
	queue->front++;
}

/** �ж϶����Ƿ������ˣ���û����������� **/
bool Queue_Is_Full(Queue* queue)
{
	if (queue->front > 0)
	{
		int step = queue->front;

		// ʱ�临�ӶȱȽϸ�
		for (int i = queue->front; i <= queue->rear; i++)
		{
			queue->data[i - step] = queue->data[i];
		}

		queue->front = 0;
		queue->rear = queue->rear - step;

		// ����û��ȫ��
		return false;
	}
	else
	{
		// ������
		return true;
	}
}

/** ��� **/
void Enter_Queue(Queue* queue, ElemType element)
{
	if (queue->rear >= MAXSIZE) // rearָ����ǿ�λ
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