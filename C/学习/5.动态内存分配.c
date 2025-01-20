#include <stdio.h>
#include <stdlib.h> // ����malloc
#include <string.h>

// ��̬�ڴ�������ھ�̬�ڴ���Եģ���ν��̬�;�̬��ָ�ڴ�ķ��䷽ʽ����̬�ڴ���ָ�ڶ�(Heap)�Ϸ�����ڴ棬����̬�ڴ���ָ��ջ(Stack)�Ϸ�����ڴ�
// �ֲ��������βΡ��������õ��ڴ涼����ջ�Ϸ���ģ�ջ�ϵ��ڴ�����ϵͳ������ͷŵģ��ռ����ޣ��ڸ������ͺ������н�����ͻᱻϵͳ�Զ��ͷ�
// �����ϵ��ڴ����ɳ���Աͨ������Լ��ֶ�������ͷŵģ��ռ�ܴ󣬴洢����


/* malloc�����ڴ� */
void testMalloc(void)
{
	int age[10]; // ������ռ�ڴ�Ϊ10 * sizeof(int)
	int* p = malloc(10*sizeof(int)); // malloc : memory allocate �ڴ���� ����ֵΪһ������ָ��

	if (!p) // ���ڴ�ռ䲻�㣬��������NULL
	{
		printf("�ڴ�����ʧ��\n");
		return;
	}

	// 1.ͨ��memset��ʼ��
	memset(p, 0, 10*sizeof(int));

	// 2.�ֶ���ʼ��
	for (int i = 0; i < 10; i++)
	{
		//*(p + i) = i * 2;
		printf("%d ", *(p + i)); // malloc���������ڴ�󲻻���ڴ���г�ʼ������������ֵ, ��Ҫ�ֶ���ֵ
	}

	// �ֶ����룬�����ֶ��ͷţ� ����ᵼ���ڴ�й¶
	free(p); // p������������ڴ�ռ���׵�ַ
	p = NULL;

	// �ͷź���ڴ治����ʹ��



}

/* calloc�����ڴ� */
void testCalloc(void)
{
	int age[10]; // ������ռ�ڴ�Ϊ10 * sizeof(int)
	int* p = calloc(10, sizeof(int));

	if (!p) // ���ڴ�ռ䲻�㣬��������NULL
	{
		printf("�ڴ�����ʧ��\n");
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
		printf("%d ", *(p + i)); // calloc���������ڴ�����ڴ��Զ���ʼ��Ϊ0
	}

	printf("\n");

	// ���䵽15��int
	// ��1��memcpy
	// 
	//int* pnew = calloc(15, sizeof(int));
	//memcpy(pnew, p, 10*sizeof(int));
	//for (int i = 0; i < 15; i++)
	//{
	//	printf("%d ", *(pnew + i));
	//}

	// ��2��realloc
	int* pnew = realloc(p, 15*sizeof(int));
	if (!pnew)
	{
		printf("�ڴ�����ʧ��\n");
		return;
	}
	for (int i = 0; i < 15; i++)
	{
		if (i >= 10)
		{
			*(pnew + i) = 60 + i;
		}
		printf("%d ", *(pnew + i)); // realloc���䲿�ֵ��ڴ治���Զ���ʼ��Ϊ0����Ϊ����ֵ
	}

	free(pnew);
	pnew = NULL;
}

int main(void)
{
	//testMalloc();
	testCalloc();

	return 0;
}