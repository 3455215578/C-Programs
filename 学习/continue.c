#include<stdio.h>
//#define GOLD 1000  �궨�� ����û�зֺ�(;)
int main(void)
{
	const int GOLD = 1000;
	int rush;
	rush = 0;
	while (rush <= GOLD)
	{
		printf("rush = %u\n", rush);
		rush++;
		if (rush == 500)//�����Ⱥ����ж�,һ���Ⱥ��Ǹ�ֵ!
		{
			rush++;
			printf("�ڵ�������,�ӵ���\n");
			continue;
		}
	}
	printf("������!\n");

	return 0;
}