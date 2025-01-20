#include "stdio.h"
#include "stdbool.h"


// 双层循环实现
void Bubble_Sort1(int* arr, unsigned int n)
{

	if (n < 2)
	{
		return;
	}

	int temp; // 比较两个元素大小交换位置时用的临时变量
	int time = 0;

	for (int i = n - 1; i > 0; i--) // n个元素需要n-1趟排序，经过一趟排序后会确定一个元素，下一趟则需要比较下标为 0到(n-2) 的元素
	{

		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("排序总趟数为: %d\n", time);
}

// 递归实现
void Bubble_Sort2(int* arr, unsigned int n)
{

	if (n < 2)
	{
		return;
	}

	int temp; // 用于交换变量的临时变量

	for (int i = 0; i < n - 1; i++)
	{

		if (arr[i] > arr[i + 1])
		{
			temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
		}

	}

	Bubble_Sort2(arr, --n); // 难点
}

// 双层循环Pro : 如果某一趟结束后没有交换元素，则认为已经完成排序，并提前结束排序
void Bubble_Sort1_Pro(int* arr, unsigned int n)
{

	if (n < 2)
	{
		return;
	}

	int temp; // 比较两个元素大小交换位置时用的临时变量
	int time = 0;


	for (int i = n - 1; i > 0; i--) // n个元素需要n-1趟排序，经过一趟排序后会确定一个元素，下一趟则需要比较下标为 0到(n-2) 的元素
	{
		bool swap_flag = false; // 每一趟都复位交换标志位  确保在数组已有序时停止排序
		time += 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap_flag = true;
			}
		}

		// 检查本趟是否有交换元素：
		// 有-true  
		// 无-false
		if (swap_flag == false)
		{
			printf("排序总趟数为: %d\n", time);
			return;
		}
	}
}

// 递归Pro: 如果某一趟结束后没有交换元素，则认为已经完成排序，并提前结束排序
void Bubble_Sort2_Pro(int* arr, unsigned int n)
{
	if (n < 2)
	{
		return;
	}

	int temp; // 用于交换变量的临时变量
	static int time; // 排序总趟数

	bool swap_flag = false; // 递归每一次都会调用这行代码，相当于复位标志位

	for (int i = 0; i < n - 1; i++) // 对于递归来说，这只是其中一趟
	{

		if (arr[i] > arr[i + 1])
		{
			temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
			swap_flag = true;

		}
	}

	time += 1;

	if (swap_flag == false)
	{
		printf("排序总趟数为: %d\n", time);
		return;
	}


	Bubble_Sort2_Pro(arr, --n); // 难点: 下一次递归时去掉最后一个元素(最大值），因为已经在本次比较完了
	                            // --n前缀递减：先减后使用

	}


int main(void)
{

	int arr[] = { 2, 1, 44, 7, 22, 6, 20, 8, 25, 10, 23, 12, 13, 66, 15};

	// 1. 1 2 7 22 6 20 8 25 10 23 12 13 44 15 66
	// 2. 1 2 7 6 20 8 22 10 23 12 13 25 15 44 66
	// 3. 1 2 6 7 8 20 10 22 12 13 23 15 25 44 66
	// 4. 1 2 6 7 8 10 20 12 13 22 15 23 25 44 66
	// 5. 1 2 6 7 8 10 12 13 20 15 22 23 25 44 66
	// 6. 1 2 6 7 8 10 12 13 15 20 22 23 25 44 66

	Bubble_Sort2_Pro(arr,15);

	printf("\n");

	// 显示排序后的结果
	for (int i = 0; i < 15; i++)
	{
		printf("%d\n", arr[i]);
	}


	return 0;
}
