#include <stdio.h>

typedef struct
{
	int year;
	int month;
	int day;
}Birthday;

typedef struct
{
	char name[100];
	int age;
	Birthday birthday;
}Student;

void Print(Student* stu)                    // ʹ�ýṹ��ָ�룬ֱ�Ӵ��ݽṹ��ĵ�ַ�����ؿ����ṹ��                                                          
{                                                              
	printf("name:%s\nage:%d\nyear:%d\nmonth:%d\nday:%d\n", stu->name, stu->age,         // ���ݽṹ��ָ��ʱ�����ʽṹ���Ա�������õ�,����Ҫ�ü�ͷ�ڲ�Ƕ�׵���ͨ�ṹ����Ȼ�õ���ʳ�Ա
		stu->birthday.year, stu->birthday.month, stu->birthday.day);                    // �ڲ�Ƕ�׵���ͨ�ṹ����Ȼ�õ���ʳ�Ա
}

int main(void)
{
	Student stu1 = { "����", 20, {2000, 10, 10}};

	/* ����ṹ��ָ�� */
	Student* p2Struct;
	p2Struct = &stu1;                      // p2Struct ���ָ��ָ��ṹ����� stu1 �ĵ�ַ

	Print(p2Struct);
	return 0;
}