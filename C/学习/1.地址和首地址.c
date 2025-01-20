#include<stdio.h>

// 内存是由很多字节组成的，每个字节都有对应的编号，这个编号就叫地址
int main(void)
{
	int age = 18;
	int* address_age = &age;
	printf("age：%d  address：%p\n", age, address_age);

	// 取地址操作得到的只有首地址， 但地址是连续的，会根据数据类型所占字节数递增
	printf("age：%d", *address_age);

	return 0;
}