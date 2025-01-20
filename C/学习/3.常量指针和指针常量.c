#include <stdio.h>

int main(void)
{
	// 被const关键字定义的变量称为只读变量 只能被访问，不能被修改
	const double PI = 3.1415926;
	//PI = 3.14;
	printf("%lf\n", PI);

	/* 指针存在最大的意义就是能够间接修改数据 */
	double* pptr = &PI; // &PI的类型为const double*
	*pptr = 3.14;
	printf("%lf\n", PI);
	
	int age = 18;

	// 1.普通指针

	int* p_age = &age; // p_age存储了变量age的内存地址
	*p_age = 19; // 解引用操作 ：访问和修改指针存储的内存地址中的数据 同时变量本身的值也被修改
	printf("%d %d\n", *p_age, age);

	int* read_age = p_age; // read_age和p_age都指向同一块地址
	printf("*read_age：%d  *p_age：%d  age：%d\n", *read_age, *p_age, age);
	printf("read_age的地址：%p\n", read_age);
	*read_age = 100;
	printf("修改值后 read_age的地址：%p\n", read_age); // 同一个变量 改变它的值不会改变它的地址
	printf("*read_age：%d   *p_age：%d  age：%d\n", *read_age, *p_age, age);




	// 2.常量指针(指针指向一个常量值，意味着不能通过这个指针修改它所指向的数据)【可访问指针存储的内存地址中的数据， 但不可通过指针修改(即解引用操作)】

	// 定义常量指针
	const int* Read_Age = p_age;

	// Error：无法通过指针修改变量值
	//*Read_Age = 18;


	// 但能通过改变指针指向
	printf("*Read_Age：%d  Read_Age指向的地址：%p\n", *Read_Age, Read_Age);
	int b = 10;
	Read_Age = &b;
	printf("修改指针指向后 *Read_Age：%d  Read_Age指向的地址：%p\n", *Read_Age, Read_Age);




	// 3.指针常量(指针是一个常量，意味着指针存储的地址不能被改变)
	int* cptr = p_age;
	printf("*cptr：%d   cptr指向的地址为：%p\n", *cptr, cptr);

	int num = 666;
	cptr = &num;
	printf("*cptr：%d   cptr指向的地址为：%p\n", *cptr, cptr); // 此时cptr改变了指向  程序复杂起来容易搞不清指针的指向


	// 定义指针常量
	int* const ptr = &num; // 意味着ptr只能指向num
	int x = 233;
	printf("*ptr：%d   ptr指向的地址为：%p\n", *ptr, ptr);

	// Error：无法改变指针指向
	//ptr = &x;

	// 但能通过指针改变数据
	*ptr = 233;
	printf("*ptr：%d   ptr指向的地址为：%p\n", *ptr, ptr);

	return 0;
}


/*
* 
* 常量指针：指针可以指向不同的变量，但指向的变量的值不能通过该指针修改
* 
* 指针常量：指针不能改变其指向的变量，但可以通过该指针修改指向的变量值
* 
*/

