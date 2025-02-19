#include<stdio.h>

int main定义(void)
{
	int ages[] = {22, 25, 26, 23, 25};

	// 定义一维数组指针，指向数组第一个元素的地址，然后通过指针的偏移去访问
	// 数组名为指向数组第一个元素的指针常量, 也代表该数组的内存大小
	int* p = ages;
	int len = sizeof(ages) / sizeof(ages[0]);

	//printf("%d ", p[0]);
	//printf("%d ", p[1]);
	//printf("%d ", p[2]);
	//printf("%d ", p[3]);

	printf("%d \n", *p);


	//for (int i = 0; i < len; i++)
	//{
	//	printf("%d ", *(p + i));
	//}

	for (int i = 0; i <= len; i++) // 只访问地址不取值，数组可以越界
	{
		printf("%p ", p + i);
	}

	printf("\n");

	// 区分ages、ages[0]、p 和 &ages
	printf(" ages   ：%p\n ", ages); // 类型: int
	printf("&ages[0]：%p\n ", &ages[0]);
	printf("p      ：%p\n ", p);
	printf("&ages  ：%p\n ", &ages); // 类型: int[5]

	// &ages表示的是整个数组的地址
	printf("%p\n ", ages + 1); // 下标为1的元素的地址
	printf("%p\n ", &ages + 1);// 首地址偏移一个数组大小后的元素的地址

	return 0;
}

int main(void)
{
	int num[3] = {1, 2, 3};
	for (int i = 0; i <= 3; i++)
	{
		printf("%p ", num + i);
	}

	//int* p = &num; // warning C4047: “初始化”:“int *”与“int (*)[3]”的间接级别不同
	int(*p)[3] = &num; //p先与*结合，表明p是指针，p可以表示为一个指向有3个整数元素的数组的指针

	printf("\n");
	printf("%p %p\n", p+1, &num+1);

	return 0;
}