#include <stdio.h>

int main(int argc, char const *argv[])
{
	//声明一个长度为5的int数组
	int a[] = {16,47,89,42,38};
	
	//输出数组的首地址（第一个元素的内存地址）
	printf("%p\n", &a);
	//输出第一个元素a[0]的地址
	printf("%p\n", &a[0]);
	return 0;
}