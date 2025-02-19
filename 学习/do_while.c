#include<stdio.h>
int main(void)
{
	const int GOLD = 1000;
	int rush;
	rush = 0;
	do
	{
		printf("rush = %u\n", rush);
		rush++;
	} while (rush <= GOLD);//当满足while的条件时执行do的代码
	return 0;
}

