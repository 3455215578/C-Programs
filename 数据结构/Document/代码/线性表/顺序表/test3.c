#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

//顺序表定义
typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

//顺序表初始化
void initList(SeqList *L)
{
	L->length = 0;
}

//尾部添加元素
int appendElem(SeqList *L, ElemType e)
{
	if (L->length>=MAXSIZE)
	{
		printf("顺序表已满\n");
		return 0;
	}

	L->data[L->length] = e;
	L->length++;
	return 1;
}

//遍历
void listElem(SeqList *L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	//声明一个线性表并初始化
	SeqList list;
	initList(&list);
	printf("初始化成功，目前长度占用%d\n",list.length);
	printf("目前占用内存%zu字节\n", sizeof(list.data));
	appendElem(&list, 88);
	appendElem(&list, 45);
	appendElem(&list, 43);
	appendElem(&list, 17);
	listElem(&list);
	return 0;
}






