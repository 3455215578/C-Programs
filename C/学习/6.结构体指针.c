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

void Print(Student* stu)                    // 使用结构体指针，直接传递结构体的地址，不必拷贝结构体                                                          
{                                                              
	printf("name:%s\nage:%d\nyear:%d\nmonth:%d\nday:%d\n", stu->name, stu->age,         // 传递结构体指针时，访问结构体成员不能再用点,而是要用箭头内部嵌套的普通结构体依然用点访问成员
		stu->birthday.year, stu->birthday.month, stu->birthday.day);                    // 内部嵌套的普通结构体依然用点访问成员
}

int main(void)
{
	Student stu1 = { "张三", 20, {2000, 10, 10}};

	/* 定义结构体指针 */
	Student* p2Struct;
	p2Struct = &stu1;                      // p2Struct 这个指针指向结构体变量 stu1 的地址

	Print(p2Struct);
	return 0;
}