#include<stdio.h>


/*

	��ά���飺�������� ������[row][col]
	�����ÿ��Ԫ��(row)����һ��һά���飬һά��������洢�ľ��Ƕ���ʱ���������ͱ���

*/

int main(void)
{
	int arr[3][4]; // ����ʱδ��ʼ��������ֵ

	// �����ά������ռ�ڴ��Ԫ�ظ���
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("%d\n", sizeof(arr)/sizeof(arr[0][0]));

	// ��ʼ��
	//int arr2[3][4] = {0};
	int arr2[3][4] = 
	{ 
		{0, 1, 6, 3},
		{0, 3, 2, 3},
		{0, 1, 2, 4}

	};

	// ���ĳһ�������е�Ԫ��
	//for (int c = 0; c < 4; c++)
	//{
	//	printf("%d ", arr2[1][c]);
	//}

	// ��������������е�Ԫ��
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