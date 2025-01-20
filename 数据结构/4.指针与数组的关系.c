#include <stdio.h>

int main(void)
{
	int arr[] = {1, 12, 32, 44, 25};
	int* p = arr;

	printf("%p\n", arr);
	printf("%p\n", p);

	// 用指针代替下标获取数组其他位置的值
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\n", *(p + i)); // 1指的是一个int类型的长度
	}

	return 0;
}