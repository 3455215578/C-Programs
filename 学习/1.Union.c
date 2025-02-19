#include "stdio.h"


// 联合：联合体中的所有成员共享同一个内存块，同一时刻只能存在一个成员

// 联合的内存大小由最大的成员所占内存大小决定(成员可以是基本类型、数组以及结构体等等)






int main(void)
{

	/*  1.定义联合变量 */

	// 法1：先定义后声明
	union test1
	{
		int office;
		char teacher[5];
	};

	union test1 a1, b1;


	// 法2：同时定义和声明
	union test2
	{
		int office;
		char teacher[5];
	} a2, b2;


	// 法3：直接声明
	union
	{
		int office;
		char teacher[5];
	} a3, b3;


	/* 2.联合的大小由内存最大的成员决定 */

	union Un
	{
		int age; // 占 4 个字节
		char str[8]; // 占 1*8 个字节
	};

	printf("%d\n", sizeof(union Un));



	/* 3.联合变量成员赋值 */

	/* (1) 一个联合变量，每次只能给一个成员赋值，一个联合变量的值就是联合变员的某一个成员值 */

	/*union Un u = { 18 };
	printf("%d\n", u.age);
	printf("%s\n", u.str);*/


	/* (2)给特定成员赋值 */

	//union Un u = {.str = "shy"};
	//printf("%s\n", u.str);



	/* 4.访问联合变量成员 */

	/* 给哪个成员赋值就访问谁 否则会产生垃圾值 */

	//printf("%d %s\n", u.age, u.str); // 第一个值就是垃圾值，原理是截取str前四个字节然后按整数形式解析

	/* 5.字节顺序 */
	/* x86架构是小端序，字节存进地址的方式为：高字节存在高地址 低字节存在低地址 */

	union Un u = { 0x12345678 }; // 实际存进计算机为：78 56 34 12

	for (int i = 0; i < 8; i++)
	{
		printf("%x ", u.str[i]);
	}

	return 0;
}