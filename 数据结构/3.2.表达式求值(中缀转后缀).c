#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef char ElemType;


typedef struct
{
	ElemType* data;
	int top; // ջ��ָ�루��˳����У�����ջ�����±�ֵ��
}Stack;

/**

	Left_Pare��������
	Right_Pare��������

	Add����
	Sub����
	Mul����
	Div����
	Mod��ȡ��

	Num������
	Eos��\0

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


/** ��ʼ��ջ **/
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
	// ջ��
	if (stack->top >= MAXSIZE - 1)
	{
		printf("ջ��\n");
		return;
	}
	else
	{
		stack->data[++stack->top] = element;
	}
}

/** ��ջ��ͬʱ���ر�ɾ����Ԫ�� **/
ElemType Pop_Stack(Stack* stack)
{
	// ��ջ
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	ElemType delete_data = stack->data[stack->top];
	stack->top--;

	return delete_data;

}

/** ��ȡջ��Ԫ�� **/
ElemType Get_Top(Stack* stack)
{
	// ��ջ
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	return stack->data[stack->top];

}

/** ����ջ **/
void Travel_Stack(Stack* stack)
{
	// ��ջ
	if (Stack_Is_Empty(stack))
	{
		return;
	}

	for (int i = 0; i <= stack->top; i++)
	{
		printf("%c\n", stack->data[i]);
	}

}

/** ���ַ���ת����ContentType����, ���ں������� **/
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

/** �������ȼ� **/
void Init_Priority(ElemType top_data, ContentType symbol_data, int* top_prior, int* symbol_prior)
{
	// ջ��Ԫ��
	// ����������ջ��ʱΪ������ȼ�����ջ��Ϊ������ȼ�
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


	// �����
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

/** ���������ջ��Ԫ�رȽ����ȼ� **/
int Compare_Priority(Stack* stack, ContentType symbol_data)
{
	// �������ȼ�
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
	// �������±�


	ElemType delete_data;

	int flag = 0;

	for (int i = 0; i <= strlen(string); i++)
	{
		switch (symbol[i])
		{
			// �������ݾ�ֱ�����
			case Num:
				result[index++] = string[i];
				break;

			// ������ֹ���ͽ���
			case Eos:
				delete_data = Get_Top(stack);
				result[index++] = delete_data;
				return result;
				break;

			// ����������ͺ�ջ��Ԫ�رȽ����ȼ�
			default:
				
				switch(Compare_Priority(stack, symbol[i]))
				{
					// ��������ȼ�����ջ��Ԫ�����ȼ�, ��ջ
					case Symbol_High:
						// ��������Ϊ��������ջ��Ԫ�ز��������ţ��������ջ�������ֱ��ջ��Ԫ��Ϊ�����ų�ջ����������������Ҳ��ջ�������
						while((symbol[i] == Right_Pare) && (Get_Top(stack) != '('))
						{
							flag = 1;
							delete_data = Pop_Stack(stack);
							result[index++] = delete_data;
						}
						// �����ų�ջ
						if ((symbol[i] == Right_Pare) && (Get_Top(stack) == '(') && (flag == 1))
						{
							delete_data = Pop_Stack(stack);
						}
						
						// ��ջ(���symbol�������žͲ���ջ��)
						if (symbol[i] == Right_Pare)
						{

						}
						else
						{
							Push_Stack(stack, string[i]);
						}

						break;

					// �����Ȱ�ջ��Ԫ�س�ջ����������õ�ǰ�������ջ
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

	// �����ȼ���͵�Ԫ�ؽ�ջ
	Push_Stack(stack, ',');

	char* result = Mid_To_Back(stack, mid);

	for (int i = 0; i < index; i++)
	{
		printf("%c\n", result[i]);
	}

	return 0;
}


