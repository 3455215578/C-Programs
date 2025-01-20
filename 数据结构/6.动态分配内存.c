#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void* CreateSpace(size_t size)
{
	void* temp;

	if ((temp = malloc(size)) != NULL)
	{
		return temp; // ��������ֵΪvoid*������ݽ��յı����������Զ�ǿת
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
	// 1.������������
	//int a = 15;
	//int* p;
	//p = CreateSpace(sizeof(int));
	//*p = a;
	//printf("%d\n", *p);
	//FreeSpace(p); // һ��Ҫ�ǵ��ͷ��ڴ�
	//printf("%d\n", *p);


	// 2.�ַ���
	//char* s; // ����дs[], �ַ���ʵ�������ַ����飬ָ��ֻҪ�洢�������׵�ַ�������Ķ���˵
	//s = CreateSpace(10*sizeof(char));
	//strcpy_s(s,sizeof("Hello"),  "Hello");
	//printf("%s\n", s);
	//FreeSpace(s);
	//printf("%s\n", s);


	//// 3.����
	//int* arr;
	//arr = CreateSpace(5*sizeof(int));
	////��ʼ������
	//for (int i = 0; i < 5; i++)
	//{
	//	arr[i] = 0;
	//}
	//// ��������
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

	// 4.�ṹ��
	Point_t* point;
	point = CreateStructSpace(sizeof(point));
	point->x = 5;
	point->y = 10;
	printf("x=%d, y=%d\n", point->x, point->y);
	return 0;
}