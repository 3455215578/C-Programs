#include <stdio.h>

int main(void)
{
	int arr[3][2] = { 
		              {1, 3},
		              {5, 2},
		              {7, 4} 
	                };

	// �����ά����ָ�� ָ���һ��Ԫ�أ���СΪһά�����Ԫ�ظ���
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