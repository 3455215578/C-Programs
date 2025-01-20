#include<stdio.h>


/*

	二维数组：数组类型 数组名[row][col]
	数组的每个元素(row)都是一个一维数组，一维数组里面存储的就是定义时的数据类型变量

*/

int main(void)
{
	int arr[3][4]; // 定义时未初始化，垃圾值

	// 计算二维数组所占内存和元素个数
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("%d\n", sizeof(arr)/sizeof(arr[0][0]));

	// 初始化
	//int arr2[3][4] = {0};
	int arr2[3][4] = 
	{ 
		{0, 1, 6, 3},
		{0, 3, 2, 3},
		{0, 1, 2, 4}

	};

	// 输出某一行所有列的元素
	//for (int c = 0; c < 4; c++)
	//{
	//	printf("%d ", arr2[1][c]);
	//}

	// 输出所有行所有列的元素
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			printf("%d ", arr2[r][c]);
		}
		printf("\n");
	}

	return 0;
};