#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** 结构体定义 **/
#define MAXSIZE 100

typedef int ElemType;

typedef struct treenode
{
	ElemType weight;
	struct treenode* left; // 也是TreeNode类型的指针
	struct treenode* right;

}TreeNode;

typedef TreeNode* BitTree;

/****************************  树  *****************************/

ElemType weight[] = { 100, 42, 15, -1, -1, 27, -1, -1, 58, 28, 13, 5, -1, -1, 8, -1, -1, 15, -1, -1, 30, -1, -1 };
int index = 0;

/** 创建树(递归) **/
/** 因为要改变指针的值，所以要用二重指针 **/
void Create_Tree(BitTree* tree)
{
	ElemType ch = weight[index++];

	if (ch == -1)
	{
		(*tree) = NULL;

	}
	else
	{
		*tree = (TreeNode*)malloc(sizeof(TreeNode));

		(*tree)->weight = ch;

		// 创建子树
		Create_Tree(&(*tree)->left);
		Create_Tree(&(*tree)->right);
	}

}

/** 计算树WPL **/
int WPL_Calc(BitTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	int depth = 0;
	int wpl = 0;

	// 用数组代替队列
	BitTree queue[MAXSIZE];
	int front = 0;
	int rear = 0;

	queue[rear] = tree;
	rear++;

	while (front != rear)
	{
		int count = rear - front;

		while (count > 0)
		{
			BitTree curr = queue[front];
			front++;

			// 为下一次的遍历准备好元素
			if (curr->left != NULL)
			{
				queue[rear] = curr->left;
				rear++;
			}

			if (curr->right != NULL)
			{
				queue[rear] = curr->right;
				rear++;
			}

			if ((curr->left == NULL) && (curr->right == NULL))
			{
				wpl += curr->weight * depth;
			}

			count--;

		}

		depth++;
	}

	return wpl;
}

int main(void)
{
	BitTree tree;
	Create_Tree(&tree);

	int wpl = WPL_Calc(tree);
	printf("%d\n", wpl);

	return 0;
}