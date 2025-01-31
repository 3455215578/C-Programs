#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef char ElemType;


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

typedef enum
{
	Very_Low,
	Low,
	Normal,
	High,
	Very_High
}Priority;

typedef enum
{
	Symbol_High,
	Other
}Priority_Result;


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

/** 获取栈顶元素 **/
ElemType Get_Top(Stack* stack)
{
	// 空栈
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	return stack->data[stack->top];

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
		printf("%c\n", stack->data[i]);
	}

}

/** 把字符串转换成ContentType类型, 便于后续处理 **/
ContentType* Transform_Symbol(const char* string)
{
	int len = strlen(string);
	ContentType* result = (ContentType*)malloc((len + 1) * sizeof(ContentType));

	for (int i = 0; i <= strlen(string); i++)
	{
		switch (string[i])
		{
		case '(':
			result[i] = Left_Pare;
			break;

		case ')':
			result[i] = Right_Pare;
			break;

		case '+':
			result[i] = Add;
			break;

		case '-':
			result[i] = Sub;
			break;

		case '*':
			result[i] = Mul;
			break;

		case '/':
			result[i] = Div;
			break;

		case '%':
			result[i] = Mod;
			break;

		case '\0':
			result[i] = Eos;
			break;

		default:
			if ((string[i] >= '0') && (string[i] <= '9'))
			{
				result[i] = Num;
			}
			break;
		}

	}

	return result;
}

/** 分配优先级 **/
void Init_Priority(ElemType top_data, ContentType symbol_data, int* top_prior, int* symbol_prior)
{
	// 栈顶元素
	// 当左括号在栈外时为最高优先级，在栈内为最低优先级
	if ((top_data == ',') || (top_data == '('))
	{
		*top_prior = Very_Low;
	}
	else if ((top_data == '+') || (top_data == '-'))
	{
		*top_prior = Normal;
	}
	else if ((top_data == '*') || (top_data == '/'))
	{
		*top_prior = High;
	}


	// 运算符
	if ((symbol_data == Add) || (symbol_data == Sub))
	{
		*symbol_prior = Normal;
	}
	else if ((symbol_data == Mul) || (symbol_data == Div))
	{
		*symbol_prior = High;
	}
	else if ((symbol_data == Left_Pare) || (symbol_data == Right_Pare))
	{
		*symbol_prior = Very_High;
	}
}

/** 将运算符和栈顶元素比较优先级 **/
int Compare_Priority(Stack* stack, ContentType symbol_data)
{
	// 分配优先级
	int top_prior;
	int symbol_prior;

	ElemType top_data = Get_Top(stack);
	Init_Priority(top_data, symbol_data, &top_prior, &symbol_prior);

	if (symbol_prior > top_prior)
	{
		return Symbol_High;
	}
	else
	{
		return Other;
	}

}

int index = 0;

/**  **/
char* Mid_To_Back(Stack* stack, const char* string)
{
	ContentType* symbol = Transform_Symbol(string);

	int len = (int)strlen(string);
	char* result = (char*)malloc(sizeof(char) * (len + 1));
	// 输出结果下标


	ElemType delete_data;

	int flag = 0;

	for (int i = 0; i <= strlen(string); i++)
	{
		switch (symbol[i])
		{
			// 遇到数据就直接输出
			case Num:
				result[index++] = string[i];
				break;

			// 遇到终止符就结束
			case Eos:
				delete_data = Get_Top(stack);
				result[index++] = delete_data;
				return result;
				break;

			// 遇到运算符就和栈顶元素比较优先级
			default:
				
				switch(Compare_Priority(stack, symbol[i]))
				{
					// 运算符优先级大于栈顶元素优先级, 进栈
					case Symbol_High:
						// 如果运算符为右括号且栈顶元素不是左括号，则持续出栈并输出，直到栈顶元素为左括号出栈结束，并将左括号也出栈但不输出
						while((symbol[i] == Right_Pare) && (Get_Top(stack) != '('))
						{
							flag = 1;
							delete_data = Pop_Stack(stack);
							result[index++] = delete_data;
						}
						// 左括号出栈
						if ((symbol[i] == Right_Pare) && (Get_Top(stack) == '(') && (flag == 1))
						{
							delete_data = Pop_Stack(stack);
						}
						
						// 进栈(如果symbol是右括号就不进栈了)
						if (symbol[i] == Right_Pare)
						{

						}
						else
						{
							Push_Stack(stack, string[i]);
						}

						break;

					// 否则先把栈顶元素出栈并输出，再让当前运算符进栈
					default:
						delete_data = Pop_Stack(stack);
						result[index++] = delete_data;
						Push_Stack(stack, string[i]);

						break;
				}

				break;



		}

	}

}

char mid[] = "8/(5-3)*4"; // 16

int main(void)
{
	Stack* stack = Init_Stack();

	// 让优先级最低的元素进栈
	Push_Stack(stack, ',');

	char* result = Mid_To_Back(stack, mid);

	for (int i = 0; i < index; i++)
	{
		printf("%c\n", result[i]);
	}

	return 0;
}


