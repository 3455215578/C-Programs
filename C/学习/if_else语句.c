#include<stdio.h>
int main(void)
{
	int age;
	printf("�������������:");
	scanf_s("%d", &age);

	if (age > 256 || age < 0)   //  || �ǻ� , && ����
	{
		printf("�������ȷ�����䣡\n");
	}
	
	else
	{
		if (age >= 50)
		{
			printf("������\n");
		}
		else if (age >= 30)    //else if (��)Ҫ��Ȼ���...
		{
			printf("����\n");
		}
		else if (age >= 18)
		{
			printf("����\n");
		}
		else
		{
			printf("Сѧ����д��ҵ");
		}

	}
	return 0;
}








