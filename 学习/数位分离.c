#include <stdio.h>
int main(void)
{

	printf("������һ����λ����:");
	int num;
	scanf_s("%d", &num);
	int sin, ten, hun;

	sin = num % 10;
	ten = (num / 10) % 10;
	hun = (num / 100) % 10;

	printf("��λ��%d,ʮλ��%d,��λ��%d",hun,ten,sin);

}