#include <stdio.h>

int main(void)
{
	int arr[] = {1, 12, 32, 44, 25};
	int* p = arr;

	printf("%p\n", arr);
	printf("%p\n", p);

	// ��ָ������±��ȡ��������λ�õ�ֵ
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\n", *(p + i)); // 1ָ����һ��int���͵ĳ���
	}

	return 0;
}