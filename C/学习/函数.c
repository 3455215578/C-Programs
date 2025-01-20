#include<stdio.h>
int sum(int number_1, int number_2);
int sun_flower = 100;
int main(void)
{
	int sun_flower = 99;
	int result = sum(114, 514);
	printf("result = %d\n", result);
	printf("sun_flower_main = %d\n", sun_flower);
	return 0;
}                                    //两函数上司下属关系,main函数下达任务，sum函数完成任务后反馈给main函数,再由result接收结果
int sum(int number_1, int number_2)
{
	int score = number_1 + number_2;
	printf("sun_flower_sum = %d\n", sun_flower);
	return score;//如果第二个函数是void就不能用return 0，因为0是int类型,return后面的值的类型要和返回值类型相同
}
