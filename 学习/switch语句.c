#include<stdio.h>
int main(void)
{
	unsigned int age;
	printf("�������������: ");
	int result = scanf_s("%3u", &age);
	if (result <= 0 || result > 256)
	{
		printf("��������ȷ�����䣡");
		return 0;
	}

	switch (age)
	{
	case 40:
		printf("��ϲ������ʮ��������\n");//��Ҫ©��"break;"!
		break;
	case 50:
		printf("��ӭ������ʮ��������\n");
		break;
	case 70:
		printf("��ӭ������ʮ��������\n");
		break;
	default:
		printf("û��Ϊ������䰲�����!");
		break;
	}
	return 0;



}