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
		return;
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

/** ɾ��ָ��λ�õ�Ԫ�� **/
void Delete_Element(SeqList* list, int pos)
{
	if (list->length > MAXSIZE)
	{
		printf("˳����Ѿ�����\n");
	}
	else if ((pos < 1) || (pos > list->length))
	{
		printf("����λ�ô���\n");
	}
	else
	{
		// 1.���Ȱ�Ҫɾ����λ�ú����Ԫ�ض���ǰŲһλ�����ǵ�Ҫ��ɾ����Ԫ��
		for (int i = pos; i < list->length; i++)
		{
			list->data[i - 1] = list->data[i];
		}

		// 2. �ٰ�˳����ȼ�1����������������ݣ���һ�β������Ḳ���������
		list->length--;
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


	Travel_List(&list);

	Delete_Element(&list, 0);

	// �ٴα���˳�����֤
	Travel_List(&list);

	return 0;
}