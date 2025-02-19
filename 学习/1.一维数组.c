#include <stdio.h>

/*

	数组：相同数据类型的集合，每个元素的地址都是连续的，并且下标(索引)是从0开始的，最大下标为 (数组大小-1)
	数组的定义：数据类型 数组名[size] = {初始值};

*/


int main定义(void)
{
	// 定义两个变量，它们存储的地址不是连续的
	int age1 = 18;
	int age2 = 20;

	printf("%d - %d = %d\n", (int) & age1, (int)&age2, (int)&age1 - (int)&age2); // 隔了32个字节


	//int ages[5]; // 数组只定义不进行初始化，都是垃圾值
	//int ages[5] = 0; // 错误	C2075	"ages": 初始化需要带括号的初始化表达式列表

	//int ages[5] = {1}; // 如果指定了一个或多个元素的值，其他未指定的值默认为0
	//int ages[5] = {1, 2, 3};

	//int ages[5] = {, , , , 6}; // 数组初始化只能从左到右依次进行，不能跳过


	int ages[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int len = sizeof(ages) / sizeof(int);

	//printf("%d %d\n", ages[-1], ages[10000]); // 数组下标越界会导致程序异常


	// 输出数组所有元素
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ages[i]);
	}

	printf("\n");
	printf("%d\n", len);

	return 0;
}


/*

	1.数组定义时，数组的长度只能是常量(const也不行)， 使用时可以是变量，也可以是常量
	2.数组每个元素的地址是连续的
	3.数组每个元素的输入

*/

#define MAX 5

int main输入(void)
{
	const int len = 5;
	//int arr[len] = { 1, 2, 3, 4, 5 };

	int arr1[5*1] = {1, 2, 3, 4, 5};
	int arr2[MAX] = {1, 2, 3, 4, 5};

	/* 通过第一个元素地址的偏移得到其他元素 */
	printf("%d\n", *&arr2[0]);
	printf("%d\n", *(&arr2[0]+1)); // 1 : 一个int类型的大小


	//for (int i = 0; i < MAX; i++)
	//{
	//	printf("%d ", &arr2[i]); // 输出每个元素的首地址 相邻元素的首地址之间相差4个字节
	//}

	for (int i = 0; i < MAX; i++)
	{
		scanf_s("%d", &arr2[i]);
	}

	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr2[i]);
	}


	return 0;
}
