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
		return ;
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
// index = 5;
// 87 56 34 43 45



// i = 5:  87 56 34 43 45 12 12
// i = 4:  87 56 34 43 45 45 12
// i = 3:  87 56 34 43 43 45 12
// i = 2:  87 56 34 34 43 45 12
// i = 1:  87 56 56 34 43 45 12

/** 在顺序表指定位置插入指定元素 **/
void Insert_Element(SeqList* list, int index, ElemType element)
{
	// 若插入的位置不在尾部则进入
	if (index != list->length - 1)
	{
		// 1.先把指定位置以及之后的元素往后挪一位
		for (int i = (list->length - 1); i >= 1; i--)
		{
			list->data[i + 1] = list->data[i];
		}

		// 2.再把指定元素插入到指定位置
		list->data[index] = element;

		// 3.最后扩充顺序表长度
		list->length++;
	}
	else 
	{
		list->data[list->length] = list->data[list->length - 1];
		list->data[list->length - 1] = element;
		list->length++;
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

	printf("%d\n", list.length);

	printf("\n");

	Travel_List(&list);

	// 在指定位置插入指定元素
	Insert_Element(&list, 5, 233);

	// 再次遍历顺序表验证
	Travel_List(&list);

	return 0;
}