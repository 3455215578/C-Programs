#include <stdio.h>

int main(void)
{
	unsigned int x;
	scanf_s("%u", &x);      // ʹ��%u��ȡ�޷�������

	// A
	if ((x % 2 == 0) && (x > 4 && x <= 12))
	{
		printf("1 ");
	}
	else
	{
		printf("0 ");
	}

	// UIM
	if ((x % 2 == 0) || (x > 4 && x <= 12))         // �������������һ���������������Զ�����
	{

		printf("1 ");
	}
	else
	{
		printf("0 ");
	}

	// B
	if ((x % 2 == 0) ^ (x > 4 && x <= 12))          // ����������ֻ������һ����������ʱ���ܽ���if
	{
		printf("1 ");
	}
	else
	{
		printf("0 ");
	}

	// ����
	if ((x % 2 == 1) || (x <= 4 || x > 12))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}

	return 0;
}