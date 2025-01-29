#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct stack
{
    ElemType data;         // 存储数据
    struct stack* next;    // 指向下一个节点
} Stack;

/** 初始化栈 **/
Stack* Init_Stack(void)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));

	stack->data = 0;
	stack->next = NULL;

	return stack;
}

/** 判断栈是否为空 **/
bool Stack_Is_Empty(Stack* stack)
{
	if (stack->next == NULL)
	{
		printf("栈空\n");
		return true;
	}
	else
	{
		return false;
	}
}

/** 进栈 **/
void Push_Stack(Stack* stack, ElemType element)
{
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->data = element;

    // 将新节点插入到头节点之后

    // 不用判断stack->next是否为空。
    //如果栈为空（即 stack->next == NULL），那么 new_stack->next 会被赋值为 NULL，表示新节点是栈中唯一的节点
    new_stack->next = stack->next; 

    stack->next = new_stack;
}

/** 出栈，同时返回被删除的元素 **/
void Pop_Stack(Stack* stack, ElemType* delete_data)
{
	// 空栈
	if (stack->next == NULL)
	{
		printf("栈空\n");
		return;
	}

	Stack* delete_stack = stack->next;
	*delete_data = delete_stack->data;

	stack->next = delete_stack->next;

	// 释放堆内存
	free(delete_stack);

}

/** 获取栈顶元素 **/
void Get_Top(Stack* stack, ElemType* top_data)
{
    // 空栈
    if (stack->next == NULL)
    {
        printf("栈空\n");
        return; // 直接返回
    }

    *top_data = stack->next->data; // 获取栈顶元素的值
}

int main(void)
{

    return 0;
}

