#include <stdio.h>

// 与基本数据类型不同，结构体是抽象的数据类型



/*  1.定义结构体的基本方法  struct 结构体名{结构体成员定义};  */

struct Student_info   
{
	int id;
	char name[100];
	int age;
};



/* 2.定义空结构体 */

struct EmptyStruct
{
	int x1;
};



int main(void)
{
/* 3.定义结构体的便捷方法  typedef关键词 */

	 /*若不使用typedef来定义结构体变量*/

	struct Student_info stu1;                         // 变量定义的格式：数据类型 + 变量名，如：int a;
	                                                  // 同理，结构体变量名也包含两部分：1.数据类型:struct Student；2.变量名：stu1

	/* 使用typedef */
	typedef struct Student_info Student;              // 先把数据类型 struct Student 定义成一个新的数据类型 Student ,再加变量定义
	Student stu2;



/* 4.两种定义结构体的方法结合 */
	typedef struct A                                 // 这里的结构体名 A 可加可不加
	{
		int x2;
	}B;

	                                                 // 解释：把 struct A 这个数据类型用typedef重新定义为 B 这个数据类型


/* 5.结构体的嵌套 */

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
		Birthday birthday;                           // 数据类型 + 变量名
	}Info;

	return 0;
}