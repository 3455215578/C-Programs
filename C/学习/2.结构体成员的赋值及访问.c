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

void Print(Person p)                                           // 定义一个打印结构体成员参数的函数，避免代码重复繁杂。需传入Person类型的结构体！                                           
{                                                              // 与结构体指针的方式相比，这种方式是通过拷贝传入的结构体，再访问其成员进行的，运行效率低下
	printf("name:%s\nage:%d\nyear:%d\nmonth:%d\nday:%d\n", p.name, p.age,
		p.birthday.year, p.birthday.month, p.birthday.day);
}

int main(void)
{
	/* 给结构体变量成员赋值 */
	Person p1 = { "邹佳佳", 26, {1998, 10, 28} };
	
	/* 访问结构体变量 */
	Print(p1);

	return 0;
}