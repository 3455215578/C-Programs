#include<stdio.h>

// �ڴ����ɺܶ��ֽ���ɵģ�ÿ���ֽڶ��ж�Ӧ�ı�ţ������žͽе�ַ
int main(void)
{
	int age = 18;
	int* address_age = &age;
	printf("age��%d  address��%p\n", age, address_age);

	// ȡ��ַ�����õ���ֻ���׵�ַ�� ����ַ�������ģ����������������ռ�ֽ�������
	printf("age��%d", *address_age);

	return 0;
}