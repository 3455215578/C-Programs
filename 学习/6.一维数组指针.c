#include<stdio.h>

int main����(void)
{
	int ages[] = {22, 25, 26, 23, 25};

	// ����һά����ָ�룬ָ�������һ��Ԫ�صĵ�ַ��Ȼ��ͨ��ָ���ƫ��ȥ����
	// ������Ϊָ�������һ��Ԫ�ص�ָ�볣��, Ҳ�����������ڴ��С
	int* p = ages;
	int len = sizeof(ages) / sizeof(ages[0]);

	//printf("%d ", p[0]);
	//printf("%d ", p[1]);
	//printf("%d ", p[2]);
	//printf("%d ", p[3]);

	printf("%d \n", *p);


	//for (int i = 0; i < len; i++)
	//{
	//	printf("%d ", *(p + i));
	//}

	for (int i = 0; i <= len; i++) // ֻ���ʵ�ַ��ȡֵ���������Խ��
	{
		printf("%p ", p + i);
	}

	printf("\n");

	// ����ages��ages[0]��p �� &ages
	printf(" ages   ��%p\n ", ages); // ����: int
	printf("&ages[0]��%p\n ", &ages[0]);
	printf("p      ��%p\n ", p);
	printf("&ages  ��%p\n ", &ages); // ����: int[5]

	// &ages��ʾ������������ĵ�ַ
	printf("%p\n ", ages + 1); // �±�Ϊ1��Ԫ�صĵ�ַ
	printf("%p\n ", &ages + 1);// �׵�ַƫ��һ�������С���Ԫ�صĵ�ַ

	return 0;
}

int main(void)
{
	int num[3] = {1, 2, 3};
	for (int i = 0; i <= 3; i++)
	{
		printf("%p ", num + i);
	}

	//int* p = &num; // warning C4047: ����ʼ����:��int *���롰int (*)[3]���ļ�Ӽ���ͬ
	int(*p)[3] = &num; //p����*��ϣ�����p��ָ�룬p���Ա�ʾΪһ��ָ����3������Ԫ�ص������ָ��

	printf("\n");
	printf("%p %p\n", p+1, &num+1);

	return 0;
}