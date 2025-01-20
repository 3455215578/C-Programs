#include "stdio.h"
#include "stdbool.h"


// ˫��ѭ��ʵ��
void Bubble_Sort1(int* arr, unsigned int n)
{

	if (n < 2)
	{
		return;
	}

	int temp; // �Ƚ�����Ԫ�ش�С����λ��ʱ�õ���ʱ����
	int time = 0;

	for (int i = n - 1; i > 0; i--) // n��Ԫ����Ҫn-1�����򣬾���һ��������ȷ��һ��Ԫ�أ���һ������Ҫ�Ƚ��±�Ϊ 0��(n-2) ��Ԫ��
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

	printf("����������Ϊ: %d\n", time);
}

// �ݹ�ʵ��
void Bubble_Sort2(int* arr, unsigned int n)
{

	if (n < 2)
	{
		return;
	}

	int temp; // ���ڽ�����������ʱ����

	for (int i = 0; i < n - 1; i++)
	{

		if (arr[i] > arr[i + 1])
		{
			temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
		}

	}

	Bubble_Sort2(arr, --n); // �ѵ�
}

// ˫��ѭ��Pro : ���ĳһ�˽�����û�н���Ԫ�أ�����Ϊ�Ѿ�������򣬲���ǰ��������
void Bubble_Sort1_Pro(int* arr, unsigned int n)
{

	if (n < 2)
	{
		return;
	}

	int temp; // �Ƚ�����Ԫ�ش�С����λ��ʱ�õ���ʱ����
	int time = 0;


	for (int i = n - 1; i > 0; i--) // n��Ԫ����Ҫn-1�����򣬾���һ��������ȷ��һ��Ԫ�أ���һ������Ҫ�Ƚ��±�Ϊ 0��(n-2) ��Ԫ��
	{
		bool swap_flag = false; // ÿһ�˶���λ������־λ  ȷ��������������ʱֹͣ����
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

		// ��鱾���Ƿ��н���Ԫ�أ�
		// ��-true  
		// ��-false
		if (swap_flag == false)
		{
			printf("����������Ϊ: %d\n", time);
			return;
		}
	}
}

// �ݹ�Pro: ���ĳһ�˽�����û�н���Ԫ�أ�����Ϊ�Ѿ�������򣬲���ǰ��������
void Bubble_Sort2_Pro(int* arr, unsigned int n)
{
	if (n < 2)
	{
		return;
	}

	int temp; // ���ڽ�����������ʱ����
	static int time; // ����������

	bool swap_flag = false; // �ݹ�ÿһ�ζ���������д��룬�൱�ڸ�λ��־λ

	for (int i = 0; i < n - 1; i++) // ���ڵݹ���˵����ֻ������һ��
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
		printf("����������Ϊ: %d\n", time);
		return;
	}


	Bubble_Sort2_Pro(arr, --n); // �ѵ�: ��һ�εݹ�ʱȥ�����һ��Ԫ��(���ֵ������Ϊ�Ѿ��ڱ��αȽ�����
	                            // --nǰ׺�ݼ����ȼ���ʹ��

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

	// ��ʾ�����Ľ��
	for (int i = 0; i < 15; i++)
	{
		printf("%d\n", arr[i]);
	}


	return 0;
}
