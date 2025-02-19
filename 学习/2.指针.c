#include <stdio.h>

int main定义(void)
{
	
	int age = 18;
	int* ptr = &age; // ptr是一个指针变量  指针变量存储谁的地址，就说它指向了谁，这里ptr指向一个int类型的内存空间

	printf("%p\n%p", ptr, &age);

	// 指针类型尽量和指针指向的类型一致

	return 0;
}

/*

	& 取地址符号  获得变量的地址  锁
    * 解引用符号  通过指针获取其指向的内存空间中的数据  钥匙
	
	ptr = &money
	-> *&money == money;
	-> *ptr == money;

*/


int main取值(void)
{

	int money = 100000;
	int* ptr = &money;

	printf("%p\n%p\n", ptr, &money); // 输出地址
	printf("%d\n%d\n", money, *ptr); // 输出数据

	printf("%d\n%d", money, *&money); // 输出数据

	return 0;
}


int main野指针(void)
{
	char* pc; // 没有指向的指针叫作野指针
	//printf("%p", pc); // 错误	C4700	使用了未初始化的局部变量“pc”
	//printf("%d", *pc); // 错误	C4700	使用了未初始化的局部变量“pc”

	printf("%p\n", &pc); // 获取指针变量自己的地址

	// 在某些编译器中野指针不报错 很危险


	// 空指针，只能用于判断指针有没有指向，不能访问
	double* pd = NULL;
	printf("%p\n", pd);
	//printf("%lf\n", *pd); // 程序异常退出

	if (pd != NULL)
	{
		printf("%lf\n", *pd);
	}
	else
	{
		printf("pd指向了NULL\n");
	}


	// 万能指针
	int score = 98;

	// 万能指针可以指向任意类型的地址，若想访问万能指针，需要强转类型
	void* pe = &score;
	//printf("%d\n", *pe);// 警告	C4477 printf格式字符串%d需要类型int的参数，但可变参数 1 拥有了类型void*
	printf("%d\n", *(int*)pe); // 强转

	// 万能指针可以自动隐式地转换为其他类型的指针
	int* pf = pe; // pe：void* -> int*
	printf("%d\n", *pf);

	return 0;
}