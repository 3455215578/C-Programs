#include <stdio.h>

int main(void)
{
	int arr[3][2] = { 
		              {1, 3},
		              {5, 2},
		              {7, 4} 
	                };

	// 定义二维数组指针 指向第一个元素，大小为一维数组的元素个数
	int(*p)[2] = arr;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			printf("%d ", p[r][c]);
		}
		printf("\n");
	}

	return 0;
}