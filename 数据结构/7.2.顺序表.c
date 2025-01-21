#include <stdio.h>

#define MAXSIZE 100 // 数组的初始长度
typedef int ElemType; // typedef关键字用于创建现有类型的别名，便于修改

typedef struct
{
	ElemType data[MAXSIZE]; // 数组只是作为存储数据的容器，对顺序表进行管理需要依靠length变量
	int length; // 当前顺序表存储的数据数

}SeqList;

/** 初始化顺序表为空表 **/
void Init_List(SeqList* list)
{
	// 数组在声明时就已经初始化了
	list->length = 0;
}

/** 在顺序表尾部添加元素 **/
void Append_Element(SeqList* list, ElemType element)
{
	if (list->length >= MAXSIZE)
	{
		printf("顺序表已满\n");
		return;
	}

	list->data[list->length] = element;
	list->length++;
}

/** 遍历顺序表 **/
void Travel_List(SeqList* list)
{
	for (int i = 0; i < list->length; i++) // 循环的是顺序表而不是内部的数组
	{
		printf("%d\n", list->data[i]);
	}
	printf("\n");
}

// 87 56 34 43 45 12
// 要在pos = 2处插入元素
// i = 5:  87 56 34 43 45 12 12
// i = 4:  87 56 34 43 45 45 12
// i = 3:  87 56 34 43 43 45 12
// i = 2:  87 56 34 34 43 45 12
// i = 1:  87 56 56 34 43 45 12

/** 在顺序表指定位置插入指定元素  在数据结构中，位置是从1开始数的 **/
void Insert_Element(SeqList* list, int pos, ElemType element)
{
	if (list->length > MAXSIZE)
	{
		printf("顺序表已经满了\n");
		return;
	}
	else if ((pos < 1) || (pos > list->length))
	{
		printf("插入位置错误\n");
		return;
	}
	else
	{
		// 1.先把指定位置以及之后的元素往后挪一位
		// 把位置转换为下标, 下标 = 位置 - 1
		for (int i = (list->length - 1); i >= (pos - 1); i--)
		{
			list->data[i + 1] = list->data[i];
		}

		// 2.再把指定元素插入到指定位置
		list->data[pos - 1] = element;

		// 3.最后扩充顺序表长度
		list->length++;
	}
}


// 87 56 34 43 45 12
// 要删除pos = 2对应的元素
// i = 2 : 87 34 34 43 45 12
// i = 3 : 87 34 43 43 45 12
// i = 4 : 87 34 43 45 45 12
// i = 5 : 87 34 43 45 12 12

/** 删除指定位置的元素 **/
void Delete_Element(SeqList* list, int pos)
{
	if (list->length > MAXSIZE)
	{
		printf("顺序表已经满了\n");
	}
	else if ((pos < 1) || (pos > list->length))
	{
		printf("插入位置错误\n");
	}
	else
	{
		// 1.首先把要删除的位置后面的元素都往前挪一位，覆盖掉要被删除的元素
		for (int i = pos; i < list->length; i++)
		{
			list->data[i - 1] = list->data[i];
		}

		// 2. 再把顺序表长度减1，舍弃最后多余的数据，下一次操作将会覆盖这个数据
		list->length--;
	}
	
}

int main(void)
{
	// 声明顺序表
	SeqList list;

	// 初始化顺序表
	Init_List(&list);
	printf("顺序表目前存储%d个元素\n", list.length);
	printf("顺序表目前占用%zu个字节\n", sizeof(list.data));

	Append_Element(&list, 87);
	Append_Element(&list, 56);
	Append_Element(&list, 34);
	Append_Element(&list, 43);
	Append_Element(&list, 45);
	Append_Element(&list, 12);


	Travel_List(&list);

	Delete_Element(&list, 0);

	// 再次遍历顺序表验证
	Travel_List(&list);

	return 0;
}