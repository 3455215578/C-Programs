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
}Person;

void Print(Person p)                                           // ����һ����ӡ�ṹ���Ա�����ĺ�������������ظ����ӡ��贫��Person���͵Ľṹ�壡                                           
{                                                              // ��ṹ��ָ��ķ�ʽ��ȣ����ַ�ʽ��ͨ����������Ľṹ�壬�ٷ������Ա���еģ�����Ч�ʵ���
	printf("name:%s\nage:%d\nyear:%d\nmonth:%d\nday:%d\n", p.name, p.age,
		p.birthday.year, p.birthday.month, p.birthday.day);
}

int main(void)
{
	/* ���ṹ�������Ա��ֵ */
	Person p1 = { "�޼Ѽ�", 26, {1998, 10, 28} };
	
	/* ���ʽṹ����� */
	Print(p1);

	return 0;
}