#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
typedef char ElemType;

typedef struct TreeNode
{
	ElemType data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

typedef TreeNode* BiTree;

typedef struct 
{
	BiTree *data;
	int top;
	
}Stack;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

//初始化
Stack* initStack()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->data = (BiTree*)malloc(sizeof(BiTree) * MAXSIZE);
	s->top = -1;
	return s;
}

//判断栈是否为空
int isEmpty(Stack *s)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

//进栈/压栈
int push(Stack *s, BiTree e)
{

	if (s->top >= MAXSIZE - 1)
	{
		printf("满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

//出栈
int pop(Stack *s, BiTree *e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int getTop(Stack *s, BiTree *e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

void createTree(BiTree *T)
{
	ElemType ch;
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

void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	printf("%c ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}


void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	inOrder(T->lchild);
	printf("%c ", T->data);
	inOrder(T->rchild);
}

void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}

	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c ", T->data);
}

void iterPreOrder(Stack *s, BiTree T)
{
	while(T != NULL || isEmpty(s) != 0)
	{
		while(T != NULL)
		{
			printf("%c ", T->data);
			push(s, T);
			T = T->lchild;
		}
		pop(s, &T);
		T = T->rchild;
	}
}

void iterInOrder(Stack *s, BiTree T)
{
	while(T != NULL || isEmpty(s) != 0)
	{
		while(T != NULL)
		{
			push(s, T);
			T = T->lchild;
		}
		pop(s, &T);
		printf("%c ", T->data);
		T = T->rchild;
	}
}

int main(int argc, char const *argv[])
{
	BiTree T;
	createTree(&T);
	Stack *s = initStack();
	//iterPreOrder(s, T);
	//printf("\n");
	postOrder(T);
	printf("\n");
	iterInOrder(s, T);
	return 0;
}