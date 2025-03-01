#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct treenode
{
	ElemType data;
	struct treenode* lchild; // Ҳ��TreeNode���͵�ָ��
	struct treenode* rchild;

	// tagΪ0ʱָ��ýڵ�ĺ��ӣ�Ϊ1ʱָ��ýڵ��ǰ������
	int ltag; // ǰ��
	int rtag; // ���

}ThreadNode;

typedef ThreadNode* ThreadTree;


char str[] = "ABDH##I##EJ###CF##G##";
int index = 0;

/** ������(�ݹ�) **/
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

		// ��������������ָ��ָ���ʼ��tag
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

// �洢��һ�εĽڵ�
ThreadNode* prev = NULL;

/** ���ڵ�Ŀ�ָ�밴�������˳���滻Ϊ����ָ��--������ **/
void Threading(ThreadTree* tree)
{
	if ((*tree) == NULL)
	{
		return;
	}

	// �������
	Threading(&(*tree)->lchild);

	if ((*tree)->lchild == NULL)
	{
		(*tree)->ltag = 1;

		// ����һ�εĽڵ���Ϊ��ǰ�ڵ��ǰ��
		(*tree)->lchild = prev;

	}

	// ����ǰ���ڵ�ĺ�̣�� 
	if (prev != NULL) // ǰ����prev��Ϊ��, ��ָ������ÿ��ܻᵼ�³������
	{
		if (prev->rchild == NULL)
		{
			prev->rtag = 1;
			prev->rchild = (*tree);
		}
	}


	// ������һ���ڵ�ʱ�����ĺ�̽ڵ���δȷ������Ҫ�ں����ı��������ж�̬���á�

	// �ѵ�ǰ�ڵ���Ϊ��һ�ε�ǰ���ڵ�
	prev = *tree;

	Threading(&(*tree)->rchild);
}

/** �������� **/
void Tree_Inorder_Threading(ThreadTree* head, ThreadTree tree)
{
	// ����ͷ�ڵ�
	// Ҫ�޸�ͷ�ڵ�(ͷָ��)��ֵ����Ҫ����Ϊ����ָ��
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

	// 1.ͷ�ڵ��lchildָ��������ĸ�
	(*head)->lchild = tree;

	// 2.ͷ�ڵ��rchildָ����������һ���ڵ�(�����������,prev�洢��������������һ���ڵ�)
	// 3.��һ���ڵ��lchildָ��ͷ�ڵ㣨��ͷ�ڵ���Ϊ���������һ���ڵ��ǰ����
	prev = (*head);
	Threading(&tree);
	(*head)->rchild = prev;

	// 4.���һ���ڵ��rchildָ��ͷ�ڵ�
	// ���ʿ�ָ��ĳ�Ա�ᵼ�³�����������Ҫ���зǿ��ж�
	if (prev != NULL)
	{
		prev->rchild = (*head);
	}

}

/** �������������� **/
void inOrder_Travel(ThreadTree head) 
{
	ThreadTree curr = head->lchild;

	// ����һ���������������ջ�ص�ͷ�ڵ�
	while (curr != head)
	{
		// ����
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
