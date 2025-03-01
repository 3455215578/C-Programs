#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct treenode
{
	ElemType data;
	struct treenode* lchild; // 也是TreeNode类型的指针
	struct treenode* rchild;

	// tag为0时指向该节点的孩子，为1时指向该节点的前驱或后继
	int ltag; // 前驱
	int rtag; // 后继

}ThreadNode;

typedef ThreadNode* ThreadTree;


char str[] = "ABDH##I##EJ###CF##G##";
int index = 0;

/** 创建树(递归) **/
void Create_Tree(ThreadTree* tree)
{
	char ch = str[index++];

	if (ch == '#')
	{
		(*tree) = NULL;

	}
	else
	{
		*tree = (ThreadTree*)malloc(sizeof(ThreadNode));

		(*tree)->data = ch;

		// 创建子树，根据指针指向初始化tag
		Create_Tree(&(*tree)->lchild);
		if ((*tree)->lchild != NULL)
		{
			(*tree)->ltag = 0;
		}

		Create_Tree(&(*tree)->rchild);
		if ((*tree)->rchild != NULL)
		{
			(*tree)->rtag = 0;
		}
	}

}

// 存储上一次的节点
ThreadNode* prev = NULL;

/** 将节点的空指针按照中序的顺序替换为线索指针--线索化 **/
void Threading(ThreadTree* tree)
{
	if ((*tree) == NULL)
	{
		return;
	}

	// 中序遍历
	Threading(&(*tree)->lchild);

	if ((*tree)->lchild == NULL)
	{
		(*tree)->ltag = 1;

		// 把上一次的节点作为当前节点的前驱
		(*tree)->lchild = prev;

	}

	// 处理前驱节点的后继（☆） 
	if (prev != NULL) // 前提是prev不为空, 空指针解引用可能会导致程序崩溃
	{
		if (prev->rchild == NULL)
		{
			prev->rtag = 1;
			prev->rchild = (*tree);
		}
	}


	// 当处理到一个节点时，它的后继节点尚未确定，需要在后续的遍历过程中动态设置。

	// 把当前节点作为下一次的前驱节点
	prev = *tree;

	Threading(&(*tree)->rchild);
}

/** 树线索化 **/
void Tree_Inorder_Threading(ThreadTree* head, ThreadTree tree)
{
	// 创建头节点
	// 要修改头节点(头指针)的值，就要声明为二重指针
	(*head) = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->data = 0;
	(*head)->lchild = NULL;
	(*head)->rchild = NULL;
	(*head)->ltag = 0;
	(*head)->rtag = 1;

	if (tree == NULL)
	{
		return;
	}

	// 1.头节点的lchild指向二叉树的根
	(*head)->lchild = tree;

	// 2.头节点的rchild指向遍历的最后一个节点(☆经过线索化后,prev存储着中序遍历的最后一个节点)
	// 3.第一个节点的lchild指向头节点（把头节点作为中序遍历第一个节点的前驱）
	prev = (*head);
	Threading(&tree);
	(*head)->rchild = prev;

	// 4.最后一个节点的rchild指向头节点
	// 访问空指针的成员会导致程序崩溃，因此要进行非空判断
	if (prev != NULL)
	{
		prev->rchild = (*head);
	}

}

/** 中序线索化遍历 **/
void inOrder_Travel(ThreadTree head) 
{
	ThreadTree curr = head->lchild;

	// 经过一次线索化遍历最终会回到头节点
	while (curr != head)
	{
		// 中序
		while (curr->ltag == 0)
		{
			curr = curr->lchild;
		}

		printf("%c\n", curr->data);

		while (curr->rtag == 1)
		{
			curr = curr->rchild;
			printf("%c\n", curr->data);
		}

		curr = curr->rchild;
	}

}

int main(void)
{
	ThreadTree tree;
	ThreadTree head;

	Create_Tree(&tree);

	Tree_Inorder_Threading(&head, tree);

	inOrder_Travel(head);

	return 0;
}
