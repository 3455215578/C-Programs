#include<stdio.h>
int exchange(int* num_1, int* num_2);
int main(void)
{
	int a, b;
	a = 5; b = 10;
	exchange(&a, &b);//&a��a�ĵ�ַ,���ݸ�num_1ָ�봢��
	printf("a = %d,b = %d\n", a, b);
	return 0;
}
int exchange(int* num_1, int* num_2)
{
	int temp;
	temp = *num_1;
	*num_1 = *num_2;
	*num_2 = temp;
}