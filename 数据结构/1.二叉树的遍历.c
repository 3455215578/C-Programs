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
int index = 0;

/** ������(�ݹ�) **/
/** ��ΪҪ�ı�ָ���ֵ������Ҫ�ö���ָ�� **/
void Create_Tree(BitTree* tree)
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

/** ǰ����� **/
void Preorder_Travel(BitTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	printf("%c\n", tree->data);
	Preorder_Travel(tree->lchild);
	Preorder_Travel(tree->rchild);
}

/** ������� **/
void Inorder_Travel(BitTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	Inorder_Travel(tree->lchild);
	printf("%c\n", tree->data);
	Inorder_Travel(tree->rchild);
}

/** ������� **/
void Postorder_Travel(BitTree tree)
{
	if (tree == NULL)
	{
		return;
	}
	Postorder_Travel(tree->lchild);
	Postorder_Travel(tree->rchild);
	printf("%c\n", tree->data);
}

int main(void)
{
	BitTree tree;
	Create_Tree(&tree);

	Inorder_Travel(tree);

	return 0;
}
