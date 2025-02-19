#include<stdio.h>
int main(void)
{
	const int ONE_KILOMETER = 1000;
	unsigned int run_meter;
	run_meter = 0;
	while (run_meter <= 1000)//当while内的条件成立时循环才会进行, 否则将会跳出循环执行下一句!
	{
		printf("%u\n", run_meter);
		run_meter++;
	}
	printf("恭喜你跑完1000米\n");
	return 0;


}

