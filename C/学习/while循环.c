#include<stdio.h>
int main(void)
{
	const int ONE_KILOMETER = 1000;
	unsigned int run_meter;
	run_meter = 0;
	while (run_meter <= 1000)//��while�ڵ���������ʱѭ���Ż����, ���򽫻�����ѭ��ִ����һ��!
	{
		printf("%u\n", run_meter);
		run_meter++;
	}
	printf("��ϲ������1000��\n");
	return 0;


}

