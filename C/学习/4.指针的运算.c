#include <stdio.h>

int main(void)
{
	char*   pc = NULL; // char型指针，指向char变量
	int*    pi = NULL; // int型指针，指向int变量
	double* pd = NULL; // double型指针，指向double变量

	printf("%p %p\n", pc, pc+1); // char占一个字节
	printf("%p %p\n", pi, pi + 1); // int占四个字节
	printf("%p %p\n", pd, pd + 1); // double占八个字节

	// 指针的 + - 并不是简单的加1，而是由指针变量的数据类型所决定的 

	// 不管什么类型的指针，它们所占的内存空间都是一样的(32位(x86)为4字节，64位(x64)为8字节)
	printf("%d\n", sizeof(pc));
	printf("%d\n", sizeof(pi));
	printf("%d\n", sizeof(pd));


	int num = 0x12345678;
	int* p_num = &num;
	printf("%x\n", *p_num);

	// short占两个字节
	short* psnum = (short*)&num; // 存储方式: 78 56 34 12
	printf("%x\n", *psnum); // 重组
	printf("%x\n", *(psnum+1));


	return 0;
}