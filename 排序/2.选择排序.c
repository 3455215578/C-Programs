#include "stdio.h"
#include "stdbool.h"

// 两次循环实现
void Select_Sort1(int* arr, unsigned int n)
{
	if (n < 2)
	{
		return;
	}

	int min_index;
	int temp;

	for (int i = 0; i < n - 1; i++)
	{
		// part1: 寻找本趟的最小值：两元素之间选择最小值，再将最小值与后面的元素比较，最终确定最小值   
 
		min_index = i; // 初始化最小值为每趟的首个元素

		for (int j = i + 1; j < n; j++)
		{    
			if (arr[j] < arr [min_index]) // 将最小值与后面的元素比较
			{
				min_index = j;
			}

		}

		// part2: 如果首个元素的下标和本趟最小值的下标不同则交换位置
		if (min_index != i)
		{
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}

// 递归实现
void Select_Sort2(int* arr, unsigned int n)
{
	if (n < 2)
	{
		return;
	}

	int min_index = 0; // 初始化最小值为第一个元素的值
	int temp;

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("\n");

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[min_index])
		{
			min_index = i;
		}
	}

	if (min_index != 0)
	{
		temp = arr[min_index];
		arr[min_index] = arr[0];
		arr[0] = temp;
	}

	Select_Sort2(arr + 1, --n); // 数组首地址+1，数组长度-1(前面的已经排好了,不用看)
}

// 两次循环实现
void Select_Sort1_Pro(int* arr, unsigned int n)
{
	if (n < 2)
	{
		return;
	}

	int min_index;
	int max_index;
	int temp;
	bool swap_flag;

// int arr[] = {44, 45, 44, 4, 23, 15, 36, 26, 21, 2, 46, 6, 19, 50, 48};

// 第0趟:              2) 45 44 4 23 15 36 26 21 44 46 6 19 48 (50   (min_index=0, max_index=14 寻找到的min和max分别是2、50   min和头换,max和尾换)
// 第1趟：           2 4) 44 45 15 36 26 21 44 46 6 19         (48 50
// 第2趟：         2 4 6) 45 15 36 26 21 44 19 44              (46 48 50
// 第3趟：      2 4 6 15) 44 36 26 21 44 19                    (45 46 48 50 
// 第4趟：   2 4 6 15 19) 36 26 21 44                          (44 45 46 48 50   最小值和最大值分站两边
// 第5趟：2 4 6 15 19 21) 26 36                                (44 44 45 46 48 50

	for (int i = 0; i < n - 1; i++)
	{
		swap_flag = false;
		min_index = i;
		max_index = (n - 1) - i;

		if (arr[min_index] > arr[max_index])
		{
			temp = max_index;
			max_index = min_index;
			min_index = temp;
		}

		// 寻找这一趟的最大值和最小值
		for (int j = i + 1; j < n - (i + 1); j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
			if (arr[(n - 1) - j] > arr[max_index])
			{
				max_index = (n - 1) - j;
			}

		}


		if (min_index != i)
		{
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
			swap_flag = true;
		}
		if (max_index != (n - 1) - i)
		{
			temp = arr[(n - 1) - i];
			arr[(n - 1) - i] = arr[max_index];
			arr[max_index] = temp;
			swap_flag = true;
		}

		if (swap_flag != true)
		{
			return;
		}
      	for (int i = 0; i < n; i++)
		{
			printf("%d\n", arr[i]);
		}
		printf("\n");
	}

	
}


int main(void)
{

	//int arr[] = {44, 45, 44, 4, 67, 15, 36, 76, 92, 2, 46, 6, 19, 50, 48};
	int arr[] = { 48, 45, 44, 4, 23, 15, 36, 26, 21, 2, 46, 6, 19, 50, 44 };

	Select_Sort1_Pro(arr, 15);

	for (int i = 0; i < 15; i++)
	{
		printf("%d\n",arr[i]);
	}

	return 0;
}
