#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef int ElemType;


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
	Left_Pare,
	Right_Pare,

	Add, 
	Sub,
	Mul, 
	Div, 
	Mod,

	Num,
	Eos
}ContentType;


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
		printf("%d\n", stack->data[i]);
	}

}

/** ���ַ���ת����ContentType����, ���ں������� **/
ContentType* Transform_Content(const char* string)
{
	int len = strlen(string);
	ContentType* result = (ContentType*)malloc((len + 1) * sizeof(ContentType));

	for (int i = 0; i <= strlen(string); i++)
	{
		switch (string[i])
		{
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

/** ���ַ����͵�����ת��Ϊint���� **/
int Str_To_Int(char str)
{
	int num = str - '0';

	return num;
}

/** ʶ����������������㣬ͬʱ���ؽ�� **/ 
int Recognize_Symbol(ContentType symbol, ElemType op1, ElemType op2)
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

/** ��׺���ʽת��׺���ʽ **/
int Back_To_Mid(Stack* stack, const char* string)
{
	ContentType* result = Transform_Content(string);

	ElemType op1, op2;
	int temp;
	
	for (int i = 0; i <= strlen(string); i++)
	{
		// �����������ջ
		if (result[i] == Num)
		{
			Push_Stack(stack, Str_To_Int(string[i]));
		}
		else if (result[i] == Eos) // ������ֹ���򵯳�
		{
			temp = Pop_Stack(stack);

			return temp;
		}
		else // �������������ݳ�ջ�����㣬�ٽ������ջ
		{
			op2 = Pop_Stack(stack);
			op1 = Pop_Stack(stack);

			temp = Recognize_Symbol(result[i], op1, op2);

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
