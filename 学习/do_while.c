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
	} while (rush <= GOLD);//������while������ʱִ��do�Ĵ���
	return 0;
}

