#include <stdio.h>

int main(void)
{
	// ��const�ؼ��ֶ���ı�����Ϊֻ������ ֻ�ܱ����ʣ����ܱ��޸�
	const double PI = 3.1415926;
	//PI = 3.14;
	printf("%lf\n", PI);

	/* ָ�����������������ܹ�����޸����� */
	double* pptr = &PI; // &PI������Ϊconst double*
	*pptr = 3.14;
	printf("%lf\n", PI);
	
	int age = 18;

	// 1.��ָͨ��

	int* p_age = &age; // p_age�洢�˱���age���ڴ��ַ
	*p_age = 19; // �����ò��� �����ʺ��޸�ָ��洢���ڴ��ַ�е����� ͬʱ���������ֵҲ���޸�
	printf("%d %d\n", *p_age, age);

	int* read_age = p_age; // read_age��p_age��ָ��ͬһ���ַ
	printf("*read_age��%d  *p_age��%d  age��%d\n", *read_age, *p_age, age);
	printf("read_age�ĵ�ַ��%p\n", read_age);
	*read_age = 100;
	printf("�޸�ֵ�� read_age�ĵ�ַ��%p\n", read_age); // ͬһ������ �ı�����ֵ����ı����ĵ�ַ
	printf("*read_age��%d   *p_age��%d  age��%d\n", *read_age, *p_age, age);




	// 2.����ָ��(ָ��ָ��һ������ֵ����ζ�Ų���ͨ�����ָ���޸�����ָ�������)���ɷ���ָ��洢���ڴ��ַ�е����ݣ� ������ͨ��ָ���޸�(�������ò���)��

	// ���峣��ָ��
	const int* Read_Age = p_age;

	// Error���޷�ͨ��ָ���޸ı���ֵ
	//*Read_Age = 18;


	// ����ͨ���ı�ָ��ָ��
	printf("*Read_Age��%d  Read_Ageָ��ĵ�ַ��%p\n", *Read_Age, Read_Age);
	int b = 10;
	Read_Age = &b;
	printf("�޸�ָ��ָ��� *Read_Age��%d  Read_Ageָ��ĵ�ַ��%p\n", *Read_Age, Read_Age);




	// 3.ָ�볣��(ָ����һ����������ζ��ָ��洢�ĵ�ַ���ܱ��ı�)
	int* cptr = p_age;
	printf("*cptr��%d   cptrָ��ĵ�ַΪ��%p\n", *cptr, cptr);

	int num = 666;
	cptr = &num;
	printf("*cptr��%d   cptrָ��ĵ�ַΪ��%p\n", *cptr, cptr); // ��ʱcptr�ı���ָ��  �������������׸㲻��ָ���ָ��


	// ����ָ�볣��
	int* const ptr = &num; // ��ζ��ptrֻ��ָ��num
	int x = 233;
	printf("*ptr��%d   ptrָ��ĵ�ַΪ��%p\n", *ptr, ptr);

	// Error���޷��ı�ָ��ָ��
	//ptr = &x;

	// ����ͨ��ָ��ı�����
	*ptr = 233;
	printf("*ptr��%d   ptrָ��ĵ�ַΪ��%p\n", *ptr, ptr);

	return 0;
}


/*
* 
* ����ָ�룺ָ�����ָ��ͬ�ı�������ָ��ı�����ֵ����ͨ����ָ���޸�
* 
* ָ�볣����ָ�벻�ܸı���ָ��ı�����������ͨ����ָ���޸�ָ��ı���ֵ
* 
*/

