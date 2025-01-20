#include<stdio.h>
//#define GOLD 1000  宏定义 后面没有分号(;)
int main(void)
{
	const int GOLD = 1000;
	int rush;
	rush = 0;
	while (rush <= GOLD)
	{
		printf("rush = %u\n", rush);
		rush++;
		if (rush == 500)//两个等号是判断,一个等号是赋值!
		{
			rush++;
			printf("挖到铁矿了,扔掉！\n");
			continue;
		}
	}
	printf("挖完了!\n");

	return 0;
}