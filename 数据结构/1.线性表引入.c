#include <stdio.h>
#include <string.h>

/** 图书管理系统 **/

typedef struct {
	long long ISBN; // 8个字节 64位, 数据范围为 -2^63 ~ 2^63 - 1 (一位是符号位)
	char name[100]; // char* name[100] 代表 name是一个包含100个字符指针的数组而不是长度为100的字符数组
	float price;
}Book;

void Create_Book(Book* book, long long ISBN, const char name[100], float price)
{
	book->ISBN = ISBN;
	strcpy_s(&book->name, sizeof(book->name), name); // strcpy_s的第二个参数应该是目标数组的大小而不是源数组的
	book->price = price;
}

int main(void)
{
	Book Program, Mcu, Compile_Theory, Compile_Language;

	Create_Book(&Program, 98856432334, "程序设计基础", 25);
	Create_Book(&Mcu, 98676454354, "单片机技术及应用", 32);
	Create_Book(&Compile_Theory, 98745354322, "编译原理", 46);
	Create_Book(&Compile_Language, 96467688768, "汇编语言程序设计教程", 21);

/**

    通过数组能否在这个"图书管理系统"中进行增删改查等操作？

**/

	return 0;
}