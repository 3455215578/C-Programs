#include <stdio.h>
#include <stdlib.h> // 调用malloc
#include <string.h>

// 动态内存是相对于静态内存而言的，所谓动态和静态是指内存的分配方式，动态内存是指在堆(Heap)上分配的内存，而静态内存是指在栈(Stack)上分配的内存
// 局部变量、形参、函数调用等内存都是在栈上分配的，栈上的内存是由系统分配和释放的，空间有限，在复合语句和函数运行结束后就会被系统自动释放
// 而堆上的内存是由程序员通过编程自己手动分配和释放的，空间很大，存储自由


/* malloc申请内存 */
void testMalloc(void)
{
	int age[10]; // 数组所占内存为10 * sizeof(int)
	int* p = malloc(10*sizeof(int)); // malloc : memory allocate 内存分配 返回值为一个万能指针

	if (!p) // 若内存空间不足，则函数返回NULL
	{
		printf("内存申请失败\n");
		return;
	}

	// 1.通过memset初始化
	memset(p, 0, 10*sizeof(int));

	// 2.手动初始化
	for (int i = 0; i < 10; i++)
	{
		//*(p + i) = i * 2;
		printf("%d ", *(p + i)); // malloc函数分配内存后不会对内存进行初始化，都是垃圾值, 需要手动赋值
	}

	// 手动申请，必须手动释放， 否则会导致内存泄露
	free(p); // p必须是申请的内存空间的首地址
	p = NULL;

	// 释放后的内存不能再使用



}

/* calloc申请内存 */
void testCalloc(void)
{
	int age[10]; // 数组所占内存为10 * sizeof(int)
	int* p = calloc(10, sizeof(int));

	if (!p) // 若内存空间不足，则函数返回NULL
	{
		printf("内存申请失败\n");
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
		printf("%d ", *(p + i)); // calloc函数分配内存后会对内存自动初始化为0
	}

	printf("\n");

	// 扩充到15个int
	// 法1：memcpy
	// 
	//int* pnew = calloc(15, sizeof(int));
	//memcpy(pnew, p, 10*sizeof(int));
	//for (int i = 0; i < 15; i++)
	//{
	//	printf("%d ", *(pnew + i));
	//}

	// 法2：realloc
	int* pnew = realloc(p, 15*sizeof(int));
	if (!pnew)
	{
		printf("内存申请失败\n");
		return;
	}
	for (int i = 0; i < 15; i++)
	{
		if (i >= 10)
		{
			*(pnew + i) = 60 + i;
		}
		printf("%d ", *(pnew + i)); // realloc扩充部分的内存不会自动初始化为0，都为垃圾值
	}

	free(pnew);
	pnew = NULL;
}

int main(void)
{
	//testMalloc();
	testCalloc();

	return 0;
}