#include<stdio.h>

int main(int argc, char const *argv[])
{
	int a = 5;
	int *p = &a;
	printf("a的地址为：%p, a的值为：%d\n",&a, a);
	printf("p的地址为：%p, p的值为：%p\n",&p, p);
	return 0;
}