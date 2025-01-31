#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct treenode
{
	ElemType data;
	struct treenode* lchild; // 也是TreeNode类型的指针
	struct treenode* rchild;

}TreeNode;

typedef TreeNode* BitTree;

char str[] = "ABDH#K###E##CFI###G#J##";

/** 创建树(递归) **/
/** 因为要改变指针的值，所以要用二重指针 **/
void Create_Tree(BitTree* tree)
{
	static int index;
	char ch = str[index++];

	if (ch == '#')
	{
		(*tree) = NULL;

	}
	else
	{
		*tree = (TreeNode*)malloc(sizeof(TreeNode));
		
		(*tree)->data = ch;
		Create_Tree(&(*tree)->lchild);
		Create_Tree(&(*tree)->rchild);
	}

}

/** 前序遍历 **/
void Pre_Travel(BitTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	printf("%c\n", tree->data);
	Pre_Travel(tree->lchild);
	Pre_Travel(tree->rchild);
}

/** 中序遍历 **/
void In_Travel(BitTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	Pre_Travel(tree->lchild);
	printf("%c\n", tree->data);
	Pre_Travel(tree->rchild);
}

/** 后序遍历 **/
void Post_Travel(BitTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	Pre_Travel(tree->lchild);
	Pre_Travel(tree->rchild);
	printf("%c\n", tree->data);
}

int main(void)
{
	BitTree tree;
	Create_Tree(&tree);

	In_Travel(tree);

	return 0;
}
