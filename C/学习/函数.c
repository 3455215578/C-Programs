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
}                                    //��������˾������ϵ,main�����´�����sum����������������main����,����result���ս��
int sum(int number_1, int number_2)
{
	int score = number_1 + number_2;
	printf("sun_flower_sum = %d\n", sun_flower);
	return score;//����ڶ���������void�Ͳ�����return 0����Ϊ0��int����,return�����ֵ������Ҫ�ͷ���ֵ������ͬ
}
