#include <stdio.h>

int main����(void)
{
	
	int age = 18;
	int* ptr = &age; // ptr��һ��ָ�����  ָ������洢˭�ĵ�ַ����˵��ָ����˭������ptrָ��һ��int���͵��ڴ�ռ�

	printf("%p\n%p", ptr, &age);

	// ָ�����;�����ָ��ָ�������һ��

	return 0;
}

/*

	& ȡ��ַ����  ��ñ����ĵ�ַ  ��
    * �����÷���  ͨ��ָ���ȡ��ָ����ڴ�ռ��е�����  Կ��
	
	ptr = &money
	-> *&money == money;
	-> *ptr == money;

*/


int mainȡֵ(void)
{

	int money = 100000;
	int* ptr = &money;

	printf("%p\n%p\n", ptr, &money); // �����ַ
	printf("%d\n%d\n", money, *ptr); // �������

	printf("%d\n%d", money, *&money); // �������

	return 0;
}


int mainҰָ��(void)
{
	char* pc; // û��ָ���ָ�����Ұָ��
	//printf("%p", pc); // ����	C4700	ʹ����δ��ʼ���ľֲ�������pc��
	//printf("%d", *pc); // ����	C4700	ʹ����δ��ʼ���ľֲ�������pc��

	printf("%p\n", &pc); // ��ȡָ������Լ��ĵ�ַ

	// ��ĳЩ��������Ұָ�벻���� ��Σ��


	// ��ָ�룬ֻ�������ж�ָ����û��ָ�򣬲��ܷ���
	double* pd = NULL;
	printf("%p\n", pd);
	//printf("%lf\n", *pd); // �����쳣�˳�

	if (pd != NULL)
	{
		printf("%lf\n", *pd);
	}
	else
	{
		printf("pdָ����NULL\n");
	}


	// ����ָ��
	int score = 98;

	// ����ָ�����ָ���������͵ĵ�ַ�������������ָ�룬��Ҫǿת����
	void* pe = &score;
	//printf("%d\n", *pe);// ����	C4477 printf��ʽ�ַ���%d��Ҫ����int�Ĳ��������ɱ���� 1 ӵ��������void*
	printf("%d\n", *(int*)pe); // ǿת

	// ����ָ������Զ���ʽ��ת��Ϊ�������͵�ָ��
	int* pf = pe; // pe��void* -> int*
	printf("%d\n", *pf);

	return 0;
}