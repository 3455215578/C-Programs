#include <stdio.h>


// ��������
void Ergodic_Arr(int* arr, int arr_length)
{
	// ����������Ϊ�������ʱ��sizeof(arr)�˻�Ϊָ���0��Ԫ�ص�ָ�룬����ֵ����������Ĵ�С������ָ��Ĵ�С(4��8�ֽڣ�ȡ����32λϵͳ����64λϵͳ)
	//printf("%d\n", sizeof(arr));


	for (int i = 0; i < arr_length; i++)
	{
		printf("%d\n", arr[i]);
	}
}


int main(void)
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int arr_length = sizeof(arr) / sizeof(arr[0]); // ��������ͨ����

	Ergodic_Arr(arr, arr_length);

	return 0;
}