#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct treenode
{
	ElemType data;
	struct treenode* lchild; // Ҳ��TreeNode���͵�ָ��
	struct treenode* rchild;

}TreeNode;

typedef TreeNode* BitTree;

char str[] = "ABDH#K###E##CFI###G#J##";

/** ������(�ݹ�) **/
/** ��ΪҪ�ı�ָ���ֵ������Ҫ�ö���ָ�� **/
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

/** ǰ����� **/
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

/** ������� **/
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

/** ������� **/
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
