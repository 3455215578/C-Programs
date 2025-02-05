#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** �ṹ�嶨�� **/
#define MAXSIZE 100

typedef char TreeType;

typedef struct treenode
{
	TreeType data;
	struct treenode* lchild; // Ҳ��TreeNode���͵�ָ��
	struct treenode* rchild;

}TreeNode;

typedef TreeNode* ElemType;

typedef struct
{
	ElemType* data;
	// ��ͷ
	int front;
	// ��β
	int rear;
}Queue;
/****************************  ��  *****************************/

char str[] = "ABDH#K###E##CFI###G#J##";
int index = 0;

/** ������(�ݹ�) **/
/** ��ΪҪ�ı�ָ���ֵ������Ҫ�ö���ָ�� **/
void Create_Tree(ElemType* tree)
{
	char ch = str[index++];

	if (ch == '#')
	{
		(*tree) = NULL;

	}
	else
	{
		*tree = (TreeNode*)malloc(sizeof(TreeNode));

		(*tree)->data = ch;

		// ��������
		Create_Tree(&(*tree)->lchild);
		Create_Tree(&(*tree)->rchild);
	}

}


/****************************  ����  *****************************/


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

int Get_QueueSize(Queue* queue)
{
	if (!Queue_Is_Empty(queue))
	{
		return (queue->rear - queue->front);
	}
	else
	{
		return 0;
	}
}


int Get_Depth(ElemType tree)
{
	if (tree == NULL)
	{
		return;
	}

	int depth = 0;

	Queue* queue = Init_Queue();
	Enter_Queue(queue, tree);

	while (!Queue_Is_Empty(queue))
	{
		int count = Get_QueueSize(queue);

		while (count > 0)
		{
			ElemType curr;
			De_Queue(queue, &curr);

			if (curr->lchild != NULL)
			{
				Enter_Queue(queue, curr->lchild);
			}

			if (curr->rchild != NULL)
			{
				Enter_Queue(queue, curr->rchild);
			}

			count--;
		}

		depth++;
	}

	return depth;
}

int main(void)
{
	ElemType tree;
	Create_Tree(&tree);

	int depth = Get_Depth(tree);
	printf("%d\n", depth);

	return 0;
}