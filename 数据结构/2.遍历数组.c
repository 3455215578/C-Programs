#include <stdio.h>


// 遍历数组
void Ergodic_Arr(int* arr, int arr_length)
{
	// 将数组名作为传入参数时，sizeof(arr)退化为指向第0个元素的指针，返回值不再是数组的大小，而是指针的大小(4或8字节，取决于32位系统还是64位系统)
	//printf("%d\n", sizeof(arr));


	for (int i = 0; i < arr_length; i++)
	{
		printf("%d\n", arr[i]);
	}
}


int main(void)
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int arr_length = sizeof(arr) / sizeof(arr[0]); // 提升代码通用性

	Ergodic_Arr(arr, arr_length);

	return 0;
}