#include<stdio.h>
int main(void)
{
	int age;
	printf("请输入你的年龄:");
	scanf_s("%d", &age);

	if (age > 256 || age < 0)   //  || 是或 , && 是且
	{
		printf("请输出正确的年龄！\n");
	}
	
	else
	{
		if (age >= 50)
		{
			printf("中老年\n");
		}
		else if (age >= 30)    //else if (再)要不然如果...
		{
			printf("中年\n");
		}
		else if (age >= 18)
		{
			printf("青年\n");
		}
		else
		{
			printf("小学生快写作业");
		}

	}
	return 0;
}








