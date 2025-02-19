#include <stdio.h>

int main(void)
{
	char*   pc = NULL; // char��ָ�룬ָ��char����
	int*    pi = NULL; // int��ָ�룬ָ��int����
	double* pd = NULL; // double��ָ�룬ָ��double����

	printf("%p %p\n", pc, pc+1); // charռһ���ֽ�
	printf("%p %p\n", pi, pi + 1); // intռ�ĸ��ֽ�
	printf("%p %p\n", pd, pd + 1); // doubleռ�˸��ֽ�

	// ָ��� + - �����Ǽ򵥵ļ�1��������ָ����������������������� 

	// ����ʲô���͵�ָ�룬������ռ���ڴ�ռ䶼��һ����(32λ(x86)Ϊ4�ֽڣ�64λ(x64)Ϊ8�ֽ�)
	printf("%d\n", sizeof(pc));
	printf("%d\n", sizeof(pi));
	printf("%d\n", sizeof(pd));


	int num = 0x12345678;
	int* p_num = &num;
	printf("%x\n", *p_num);

	// shortռ�����ֽ�
	short* psnum = (short*)&num; // �洢��ʽ: 78 56 34 12
	printf("%x\n", *psnum); // ����
	printf("%x\n", *(psnum+1));


	return 0;
}