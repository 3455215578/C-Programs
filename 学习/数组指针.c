#include<stdio.h>
int main(void)
{
	int var[] = { 10,50,100 };
	int* p = &var;
	printf("var的地址 = %p\n", &var);
	printf("var的address = %p\n", p);

	const int MAX = 3;
	int number;
	number = 0;
	for (number = 0; number < MAX; number++)
	{
		printf("var[%d]的地址:%p\n", number, p);//用指针表示,因为后面用指针递增
		printf("var[%d]的值:%d\n", number, *p);
		p++;
	}
	return 0;
}