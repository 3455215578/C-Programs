#include "stdio.h"
#include "stdbool.h"

// ����ѭ��ʵ��
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
		// part1: Ѱ�ұ��˵���Сֵ����Ԫ��֮��ѡ����Сֵ���ٽ���Сֵ������Ԫ�رȽϣ�����ȷ����Сֵ   
 
		min_index = i; // ��ʼ����СֵΪÿ�˵��׸�Ԫ��

		for (int j = i + 1; j < n; j++)
		{    
			if (arr[j] < arr [min_index]) // ����Сֵ������Ԫ�رȽ�
			{
				min_index = j;
			}

		}

		// part2: ����׸�Ԫ�ص��±�ͱ�����Сֵ���±겻ͬ�򽻻�λ��
		if (min_index != i)
		{
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}

// �ݹ�ʵ��
void Select_Sort2(int* arr, unsigned int n)
{
	if (n < 2)
	{
		return;
	}

	int min_index = 0; // ��ʼ����СֵΪ��һ��Ԫ�ص�ֵ
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

	Select_Sort2(arr + 1, --n); // �����׵�ַ+1�����鳤��-1(ǰ����Ѿ��ź���,���ÿ�)
}

// ����ѭ��ʵ��
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

// ��0��:              2) 45 44 4 23 15 36 26 21 44 46 6 19 48 (50   (min_index=0, max_index=14 Ѱ�ҵ���min��max�ֱ���2��50   min��ͷ��,max��β��)
// ��1�ˣ�           2 4) 44 45 15 36 26 21 44 46 6 19         (48 50
// ��2�ˣ�         2 4 6) 45 15 36 26 21 44 19 44              (46 48 50
// ��3�ˣ�      2 4 6 15) 44 36 26 21 44 19                    (45 46 48 50 
// ��4�ˣ�   2 4 6 15 19) 36 26 21 44                          (44 45 46 48 50   ��Сֵ�����ֵ��վ����
// ��5�ˣ�2 4 6 15 19 21) 26 36                                (44 44 45 46 48 50

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

		// Ѱ����һ�˵����ֵ����Сֵ
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
