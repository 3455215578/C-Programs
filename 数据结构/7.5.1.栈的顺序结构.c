#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
	ElemType* data;
	int top; // ’ª∂•÷∏’Î£®‘⁄À≥–Ú±Ì÷–£¨æÕ «’ª∂•µƒœ¬±Í÷µ£©
}Stack;

/** ≥ı ºªØ’ª **/
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
		printf("’ªø’\n");
		return true;
	}
	else 
	{
		return false;
	}
}

/** Ω¯’ª **/
void Push_Stack(Stack* stack, ElemType element)
{
	// ’ª¬˙
	if (stack->top >= MAXSIZE - 1)
	{
		printf("’ª¬˙\n");
		return NULL;
	}
	else
	{
		stack->data[++stack->top] = element;
	}
}

/** ≥ˆ’ª£¨Õ¨ ±∑µªÿ±ª…æ≥˝µƒ‘™Àÿ **/
void Pop_Stack(Stack* stack, ElemType* delete_data)
{
	// ø’’ª
	if (stack->top == -1)
	{
		printf("ø’’ª\n");
		return NULL;
	}
	else 
	{
		*delete_data = stack->data[stack->top];
		stack->top--;
	}
}

void Get_Top(Stack* stack, ElemType* top_data)
{
	// ø’’ª
	if (stack->top == -1)
	{
		printf("ø’’ª\n");
		return NULL;
	}
	else
	{
		*top_data = stack->data[stack->top];
	}
}

void Travel_Stack(Stack* stack)
{
	// ø’’ª
	if (stack->top == -1)
	{
		printf("ø’’ª\n");
		return NULL;
	}
	else
	{
		for (int i = 0; i <= stack->top; i++)
		{
			printf("%d\n", stack->data[i]);
		}
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