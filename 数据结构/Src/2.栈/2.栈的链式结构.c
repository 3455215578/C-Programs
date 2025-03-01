#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct stack
{
    ElemType data;         // �洢����
    struct stack* next;    // ָ����һ���ڵ�
} Stack;

/** ��ʼ��ջ **/
Stack* Init_Stack(void)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));

	stack->data = 0;
	stack->next = NULL;

	return stack;
}

/** �ж�ջ�Ƿ�Ϊ�� **/
bool Stack_Is_Empty(Stack* stack)
{
	if (stack->next == NULL)
	{
		printf("ջ��\n");
		return true;
	}
	else
	{
		return false;
	}
}

/** ��ջ **/
void Push_Stack(Stack* stack, ElemType element)
{
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->data = element;

    // ���½ڵ���뵽ͷ�ڵ�֮��

    // �����ж�stack->next�Ƿ�Ϊ�ա�
    //���ջΪ�գ��� stack->next == NULL������ô new_stack->next �ᱻ��ֵΪ NULL����ʾ�½ڵ���ջ��Ψһ�Ľڵ�
    new_stack->next = stack->next; 

    stack->next = new_stack;
}

/** ��ջ��ͬʱ���ر�ɾ����Ԫ�� **/
void Pop_Stack(Stack* stack, ElemType* delete_data)
{
	// ��ջ
	if (stack->next == NULL)
	{
		printf("ջ��\n");
		return;
	}

	Stack* delete_stack = stack->next;
	*delete_data = delete_stack->data;

	stack->next = delete_stack->next;

	// �ͷŶ��ڴ�
	free(delete_stack);

}

/** ��ȡջ��Ԫ�� **/
void Get_Top(Stack* stack, ElemType* top_data)
{
    // ��ջ
    if (stack->next == NULL)
    {
        printf("ջ��\n");
        return; // ֱ�ӷ���
    }

    *top_data = stack->next->data; // ��ȡջ��Ԫ�ص�ֵ
}

int main(void)
{

    return 0;
}

