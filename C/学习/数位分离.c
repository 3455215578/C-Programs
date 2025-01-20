#include <stdio.h>
int main(void)
{

	printf("请输入一个三位整数:");
	int num;
	scanf_s("%d", &num);
	int sin, ten, hun;

	sin = num % 10;
	ten = (num / 10) % 10;
	hun = (num / 100) % 10;

	printf("百位是%d,十位是%d,个位是%d",hun,ten,sin);

}