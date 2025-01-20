#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void* CreateSpace(size_t size)
{
	void* temp;

	if ((temp = malloc(size)) != NULL)
	{
		return temp; // 函数返回值为void*，会根据接收的变量的类型自动强转
	}

}

void FreeSpace(void* p)
{
	free(p);
}

char* CreateStrSpace(int str_length, const char* str)
{
	char* temp;
	temp = CreateSpace(str_length * sizeof(char));
	if (temp != NULL)
	{
		strcpy_s(temp, str_length, str);
		return temp;
	}

}

int* CreateArrSpace(int size)
{
	int* temp = CreateSpace(size);
	if (temp != NULL)
	{
		for (int i = 0; i < size / sizeof(int); i++)
		{
			temp[i] = 0;
		}
		return temp;
	}

}

typedef struct {

	int x;
	int y;

}Point_t;

Point_t* CreateStructSpace(int size)
{
	Point_t* temp = CreateSpace(size);
	if (temp != NULL)
	{
		return temp;
	}

}

int main(void)
{
	// 1.基本数据类型
	//int a = 15;
	//int* p;
	//p = CreateSpace(sizeof(int));
	//*p = a;
	//printf("%d\n", *p);
	//FreeSpace(p); // 一定要记得释放内存
	//printf("%d\n", *p);


	// 2.字符串
	//char* s; // 不能写s[], 字符串实际上是字符数组，指针只要存储着它的首地址，其他的都好说
	//s = CreateSpace(10*sizeof(char));
	//strcpy_s(s,sizeof("Hello"),  "Hello");
	//printf("%s\n", s);
	//FreeSpace(s);
	//printf("%s\n", s);


	//// 3.数组
	//int* arr;
	//arr = CreateSpace(5*sizeof(int));
	////初始化数组
	//for (int i = 0; i < 5; i++)
	//{
	//	arr[i] = 0;
	//}
	//// 遍历数组
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d\n", *(arr+i));
	//}
	//FreeSpace(arr);
	//printf("\n");
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d\n", *(arr + i));
	//}

	// 4.结构体
	Point_t* point;
	point = CreateStructSpace(sizeof(point));
	point->x = 5;
	point->y = 10;
	printf("x=%d, y=%d\n", point->x, point->y);
	return 0;
}