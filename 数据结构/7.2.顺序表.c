#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // ����ĳ�ʼ����
typedef int ElemType; // typedef�ؼ������ڴ����������͵ı����������޸�

typedef struct
{
	ElemType* data; // ����ֻ����Ϊ�洢���ݵ���������˳�����й�����Ҫ����length����
	int length; // ��ǰ˳���洢��������

}SeqList;


/** ջ�ڴ��ֳ��Զ��ڴ棬���ķ�����ͷŶ�����Ϊ���ɿصģ�Ϊ����˳����ڴ�ռ䱻�����ͷţ��ڶ��ڴ��н��ж�̬�ڴ�����ʼ�� **/

/** ��ʼ������������һ���ַ������ʼ��˳��������������а�����ַ��ֵ��ͬ���͵�ָ���������û���ظ����� **/
SeqList* Init_List()
{
	SeqList* list = (SeqList*)malloc(sizeof(SeqList));
	list->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	list->length = 0;

	return list;
}

/** ��˳���β�����Ԫ�� **/
void Append_Element(SeqList* list, ElemType element)
{
	if (list->length >= MAXSIZE)
	{
		printf("˳�������\n");
		return;
	}

	list->data[list->length] = element;
	list->length++;
}

/** ����˳��� **/
void Travel_List(SeqList* list)
{
	if (list->length == 0)
	{
		printf("�ձ�\n");
	}
	else
	{
		for (int i = 0; i < list->length; i++) // ѭ������˳���������ڲ�������
		{
			printf("%d\n", list->data[i]);
		}
	}


}

// 87 56 34 43 45 12
// Ҫ��pos = 2������Ԫ��
// i = 5:  87 56 34 43 45 12 12
// i = 4:  87 56 34 43 45 45 12
// i = 3:  87 56 34 43 43 45 12
// i = 2:  87 56 34 34 43 45 12
// i = 1:  87 56 56 34 43 45 12

/** ��˳���ָ��λ�ò���ָ��Ԫ��  �����ݽṹ�У�λ���Ǵ�1��ʼ���� **/
void Insert_Element(SeqList* list, int pos, ElemType element)
{
	if (list->length > MAXSIZE)
	{
		printf("˳����Ѿ�����\n");
		return;
	}
	else if ((pos < 1) || (pos > list->length))
	{
		printf("����λ�ô���\n");
		return;
	}
	else
	{
		// 1.�Ȱ�ָ��λ���Լ�֮���Ԫ������Ųһλ
		// ��λ��ת��Ϊ�±�, �±� = λ�� - 1
		for (int i = (list->length - 1); i >= (pos - 1); i--)
		{
			list->data[i + 1] = list->data[i];
		}

		// 2.�ٰ�ָ��Ԫ�ز��뵽ָ��λ��
		list->data[pos - 1] = element;

		// 3.�������˳�����
		list->length++;
	}
}


// 87 56 34 43 45 12
// Ҫɾ��pos = 2��Ӧ��Ԫ��
// i = 2 : 87 34 34 43 45 12
// i = 3 : 87 34 43 43 45 12
// i = 4 : 87 34 43 45 45 12
// i = 5 : 87 34 43 45 12 12

/** ɾ��ָ��λ�õ�Ԫ��, �����ر�ɾ����Ԫ�ص�ֵ **/
void Delete_Element(SeqList* list, int pos, ElemType* Element)
{
	if (list->length == 0)
	{
		printf("�ձ�\n");
	}
	else if ((pos < 1) || (pos > list->length))
	{
		printf("����λ�ô���\n");
	}
	else
	{
		// ���ر�ɾ����Ԫ�ص�ֵ
		*Element = list->data[pos - 1];
		printf("ɾ����Ԫ��Ϊ%d\n", *Element);

		// 1.���Ȱ�Ҫɾ����λ�ú����Ԫ�ض���ǰŲһλ�����ǵ�Ҫ��ɾ����Ԫ��
		for (int i = pos; i < list->length; i++)
		{
			list->data[i - 1] = list->data[i];
		}

		// 2. �ٰ�˳����ȼ�1����������������ݣ���һ�β������Ḳ���������
		list->length--;
	}

}

/** Ѱ��ָ��Ԫ�ض�Ӧ��λ�� **/
int Find_Element(SeqList* list, ElemType element)
{
	for (int i = 0; i < list->length; i++)
	{
		if (list->data[i] == element)
		{
			return (i + 1);
		}
	}
}

int main(void)
{
	SeqList* list = Init_List();

	int find_pos;

	// ��ʼ��˳���
	Init_List(&list);
	printf("˳���Ŀǰ�洢%d��Ԫ��\n", list->length);
	printf("˳���Ŀǰռ��%zu���ֽ�\n", sizeof(list->data));

	Append_Element(list, 87);
	Append_Element(list, 56);
	Append_Element(list, 34);
	Append_Element(list, 43);
	Append_Element(list, 45);
	Append_Element(list, 12);


	Travel_List(list);

	printf("\n");
	// �ٴα���˳�����֤
	Travel_List(list);

	return 0;
}