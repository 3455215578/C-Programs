#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef int ElemType;


typedef struct
{
	ElemType* data;
	int top; // 栈顶指针（在顺序表中，就是栈顶的下标值）
}Stack;

/**

	Left_Pare：左括号
	Right_Pare：右括号

	Add：加
	Sub：减
	Mul：乘
	Div：除
	Mod：取余

	Num：数字
	Eos：\0

**/

typedef enum
{
	Left_Pare,  // 0
	Right_Pare, // 1

	Add,        // 2
	Sub,        // 3
	Mul, 		// 4
	Div, 		// 5
	Mod,        // 6

	Num,		// 7
	Eos			// 8
}ContentType;


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
ElemType Pop_Stack(Stack* stack)
{
	// 空栈
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	ElemType delete_data = stack->data[stack->top];
	stack->top--;

	return delete_data;

}

/** 遍历栈 **/
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

/** 把字符串转换成ContentType类型, 便于后续处理 **/
ContentType* Transform_Symbol(const char* string)
{
	int len = strlen(string);
	ContentType* symbol = (ContentType*)malloc((len + 1) * sizeof(ContentType));

	for (int i = 0; i <= strlen(string); i++)
	{
		switch (string[i])
		{
			case '(':
				symbol[i] = Left_Pare;
				break;

			case ')':
				symbol[i] = Right_Pare;
				break;

			case '+':
				symbol[i] = Add;
				break;

			case '-':
				symbol[i] = Sub;
				break;

			case '*':
				symbol[i] = Mul;
				break;

			case '/':
				symbol[i] = Div;
				break;

			case '%':
				symbol[i] = Mod;
				break;

			case '\0':
				symbol[i] = Eos;
				break;

			default:
				if ((string[i] >= '0') && (string[i] <= '9'))
				{
					symbol[i] = Num;
				}
				break;
		}

	}

	return symbol;
}

/** 将字符类型的数字转换为int类型 **/
int Str_To_Int(char str)
{
	int num = str - '0';

	return num;
}

/** 识别运算符并进行运算，同时返回结果 **/ 
int Calc(ContentType symbol, ElemType op1, ElemType op2)
{
	int temp;

	switch (symbol)
	{
	case Add:
		temp = op1 + op2;
		break;

	case Sub:
		temp = op1 - op2;
		break;

	case Mul:
		temp = op1 * op2;
		break;

	case Div:
		temp = op1 / op2;
		break;

	case Mod:
		temp = op1 % op2;
		break;

	default:
		break;
	}

	return temp;
}

/** 进出栈处理 **/
int Back_To_Mid(Stack* stack, const char* string)
{
	ContentType* symbol = Transform_Symbol(string);

	ElemType op1, op2;
	int temp;
	
	for (int i = 0; i <= strlen(string); i++)
	{
		// 遇到数据则进栈
		if (symbol[i] == Num)
		{
			Push_Stack(stack, Str_To_Int(string[i]));
		}
		else if (symbol[i] == Eos) // 遇到终止符则弹出
		{
			temp = Pop_Stack(stack);

			return temp;
		}
		else // 遇到符号则将数据出栈并运算，再将结果进栈
		{
			op2 = Pop_Stack(stack);
			op1 = Pop_Stack(stack);

			temp = Calc(symbol[i], op1, op2);

			Push_Stack(stack, temp);
		}
	}

}

char back[] = "82/2+56*-";

int main(void)
{
	Stack* stack = Init_Stack();

	int value = Back_To_Mid(stack, back);

	printf("%d\n", value);

	return 0;
}
