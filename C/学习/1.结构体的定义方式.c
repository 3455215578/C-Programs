#include <stdio.h>

// ������������Ͳ�ͬ���ṹ���ǳ������������



/*  1.����ṹ��Ļ�������  struct �ṹ����{�ṹ���Ա����};  */

struct Student_info   
{
	int id;
	char name[100];
	int age;
};



/* 2.����սṹ�� */

struct EmptyStruct
{
	int x1;
};



int main(void)
{
/* 3.����ṹ��ı�ݷ���  typedef�ؼ��� */

	 /*����ʹ��typedef������ṹ�����*/

	struct Student_info stu1;                         // ��������ĸ�ʽ���������� + ���������磺int a;
	                                                  // ͬ���ṹ�������Ҳ���������֣�1.��������:struct Student��2.��������stu1

	/* ʹ��typedef */
	typedef struct Student_info Student;              // �Ȱ��������� struct Student �����һ���µ��������� Student ,�ټӱ�������
	Student stu2;



/* 4.���ֶ���ṹ��ķ������ */
	typedef struct A                                 // ����Ľṹ���� A �ɼӿɲ���
	{
		int x2;
	}B;

	                                                 // ���ͣ��� struct A �������������typedef���¶���Ϊ B �����������


/* 5.�ṹ���Ƕ�� */

	typedef struct
	{
		int year;
		int month;
		int day;
	}Birthday;

	typedef struct Student_info
	{
		int id;
		char name[100];
		int age;
		Birthday birthday;                           // �������� + ������
	}Info;

	return 0;
}