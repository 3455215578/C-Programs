#include<stdio.h>
int main(void)
{
	int number = 100;
	int* p_one = &number;
	int** p_two = &p_one;

	printf("ͨ��ָ��1�õ�number��ֵ:%d\n", *p_one);
	printf("ͨ��ָ��2�õ�number��ֵ:%d\n", **p_two);
	printf("number�ĵ�ַ:%p\n", p_one);
	printf("ָ��1�ĵ�ַ:%p\n", p_two);
	printf("ָ��2�ĵ�ַ:%p\n", &p_two);


}