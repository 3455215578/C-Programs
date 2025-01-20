#include<stdio.h>
int main(void)
{
	unsigned int age;
	printf("请输入你的年龄: ");
	int result = scanf_s("%3u", &age);
	if (result <= 0 || result > 256)
	{
		printf("请输入正确的年龄！");
		return 0;
	}

	switch (age)
	{
	case 40:
		printf("恭喜你获得四十岁大礼包！\n");//不要漏掉"break;"!
		break;
	case 50:
		printf("欢迎你获得五十岁大礼包！\n");
		break;
	case 70:
		printf("欢迎你获得七十岁大礼包！\n");
		break;
	default:
		printf("没有为你的年龄安排礼包!");
		break;
	}
	return 0;



}