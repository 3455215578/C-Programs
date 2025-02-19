#include<stdio.h>
int main(void)
{
	int number = 100;
	int* p_one = &number;
	int** p_two = &p_one;

	printf("通过指针1得到number的值:%d\n", *p_one);
	printf("通过指针2得到number的值:%d\n", **p_two);
	printf("number的地址:%p\n", p_one);
	printf("指针1的地址:%p\n", p_two);
	printf("指针2的地址:%p\n", &p_two);


}