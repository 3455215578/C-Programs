#include <stdio.h>

int main(void)
{
	unsigned int x;
	scanf_s("%u", &x);      // 使用%u读取无符号整数

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
	if ((x % 2 == 0) || (x > 4 && x <= 12))         // 或运算符：至少一个条件成立，可以都成立
	{

		printf("1 ");
	}
	else
	{
		printf("0 ");
	}

	// B
	if ((x % 2 == 0) ^ (x > 4 && x <= 12))          // 异或运算符：只有其中一个条件成立时才能进入if
	{
		printf("1 ");
	}
	else
	{
		printf("0 ");
	}

	// 正妹
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