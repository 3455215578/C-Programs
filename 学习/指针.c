#include<stdio.h>
int main(void)
{
	int sun_flower = 100;
	int* p = &sun_flower;//指针存储sun_flower的地址,加取地址符
	printf("输出sun_flower的真实数值:%d\n", sun_flower);
	printf("通过指针输出sun_flower的真实数值:%d\n", *p);//*是解引用,输出指针存储的地址的值
	printf("sun_flower_address = %p\n", p);
	return 0;

}