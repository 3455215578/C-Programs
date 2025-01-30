#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** 先进后出 **/

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
	ElemType* data;
	int top; // 栈顶指针（在顺序表中，就是栈顶的下标值）
}Stack;

/** 初始化栈 **/
Stack* Init_Stack(void)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	stack->top = -1;

	return stack;
}

bool Stack_Is_Empty(Stack* stack)
{
	if (stack->top == -1)
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
	// 栈满
	if (stack->top >= MAXSIZE - 1)
	{
		printf("栈满\n");
		return;
	}
	else
	{
		stack->data[++stack->top] = element;
	}
}

/** 出栈，同时返回被删除的元素 **/
void Pop_Stack(Stack* stack, ElemType* delete_data)
{
	// 空栈
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	*delete_data = stack->data[stack->top];
	stack->top--;

}

void Get_Top(Stack* stack, ElemType* top_data)
{
	// 空栈
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	*top_data = stack->data[stack->top];

}

void Travel_Stack(Stack* stack)
{
	// 空栈
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	for (int i = 0; i <= stack->top; i++)
	{
		printf("%d\n", stack->data[i]);
	}
	
}

int main(void)
{
	Stack* stack = Init_Stack();

	
	Push_Stack(stack, 1);
	Push_Stack(stack, 2);
	Push_Stack(stack, 3);

	ElemType delete_data;
	ElemType top_data;

	Pop_Stack(stack, &delete_data);
	Get_Top(stack, &top_data);

	printf("%d\n", delete_data);
	printf("%d\n", top_data);

	return 0;
}