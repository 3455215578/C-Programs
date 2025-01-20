#include <stdio.h>

#define MAXSIZE 100 // ����ĳ�ʼ����
typedef int ElemType; // typedef�ؼ������ڴ����������͵ı����������޸�

typedef struct
{
	ElemType data[MAXSIZE]; // ����ֻ����Ϊ�洢���ݵ���������˳�����й�����Ҫ����length����
	int length; // ��ǰ˳���洢��������

}SeqList;

/** ��ʼ��˳���Ϊ�ձ� **/
void Init_List(SeqList* list)
{
	// ����������ʱ���Ѿ���ʼ����
	list->length = 0;
}

/** ��˳���β�����Ԫ�� **/ 
void Append_Element(SeqList* list, ElemType element)
{
	if (list->length >= MAXSIZE)
	{
		printf("˳�������\n");
		return ;
	}

	list->data[list->length] = element;
	list->length++;
}

/** ����˳��� **/
void Travel_List(SeqList* list)
{
	for (int i = 0; i < list->length; i++) // ѭ������˳���������ڲ�������
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

/** ��˳���ָ��λ�ò���ָ��Ԫ�� **/
void Insert_Element(SeqList* list, int index, ElemType element)
{
	// �������λ�ò���β�������
	if (index != list->length - 1)
	{
		// 1.�Ȱ�ָ��λ���Լ�֮���Ԫ������Ųһλ
		for (int i = (list->length - 1); i >= 1; i--)
		{
			list->data[i + 1] = list->data[i];
		}

		// 2.�ٰ�ָ��Ԫ�ز��뵽ָ��λ��
		list->data[index] = element;

		// 3.�������˳�����
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
	// ����˳���
	SeqList list;

	// ��ʼ��˳���
	Init_List(&list);
	printf("˳���Ŀǰ�洢%d��Ԫ��\n", list.length);
	printf("˳���Ŀǰռ��%zu���ֽ�\n", sizeof(list.data));

	Append_Element(&list, 87);
	Append_Element(&list, 56);
	Append_Element(&list, 34);
	Append_Element(&list, 43);
	Append_Element(&list, 45);
	Append_Element(&list, 12);

	printf("%d\n", list.length);

	printf("\n");

	Travel_List(&list);

	// ��ָ��λ�ò���ָ��Ԫ��
	Insert_Element(&list, 5, 233);

	// �ٴα���˳�����֤
	Travel_List(&list);

	return 0;
}