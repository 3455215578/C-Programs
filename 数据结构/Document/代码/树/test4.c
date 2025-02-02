#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char TreeType;

typedef struct TreeNode
{
	TreeType data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

typedef TreeNode* ElemType;

typedef struct 
{
	ElemType *data;
	int front;
	int rear;
	
}Queue;

typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

void createTree(BiTree *T)
{
	TreeType ch;
	ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;		
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);

	}
}

//初始化
Queue* initQueue()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	q->front = 0;
	q->rear = 0;
	return q;
}

//判断队列是否为空
int isEmpty(Queue *Q)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 1;
	}
	else
	{
		return 0;	
	}
}

//入队
int equeue(Queue *Q, ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}

//出队
int dequeue(Queue *Q, ElemType *e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

//获取队头元素
int getHead(Queue *Q, ElemType *e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}

//获取队列元素数量
int queueSize(Queue *Q)
{
	if (!isEmpty(Q))
	{
		return Q->rear - Q->front;
	}
	else
	{
		return 0;
	}
}

int maxDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int depth = 0;
	Queue *q = initQueue();
	equeue(q, root);

	while(!isEmpty(q))
	{
		int count = queueSize(q);
		while(count > 0)
		{
			TreeNode* curr;
			dequeue(q, &curr);
			if (curr->lchild != NULL)
			{
				equeue(q, curr->lchild);
			}
			if (curr->rchild != NULL)
			{
				equeue(q, curr->rchild);
			}
			count--;
		}
		depth++;
	}
	return depth;
}

int main(int argc, char const *argv[])
{
	
	BiTree T;
	createTree(&T);
	printf("%d\n", maxDepth(T));

	return 0;
}



