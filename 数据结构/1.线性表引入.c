#include <stdio.h>
#include <string.h>

/** ͼ�����ϵͳ **/

typedef struct {
	long long ISBN; // 8���ֽ� 64λ, ���ݷ�ΧΪ -2^63 ~ 2^63 - 1 (һλ�Ƿ���λ)
	char name[100]; // char* name[100] ���� name��һ������100���ַ�ָ�����������ǳ���Ϊ100���ַ�����
	float price;
}Book;

void Create_Book(Book* book, long long ISBN, const char name[100], float price)
{
	book->ISBN = ISBN;
	strcpy_s(&book->name, sizeof(book->name), name); // strcpy_s�ĵڶ�������Ӧ����Ŀ������Ĵ�С������Դ�����
	book->price = price;
}

int main(void)
{
	Book Program, Mcu, Compile_Theory, Compile_Language;

	Create_Book(&Program, 98856432334, "������ƻ���", 25);
	Create_Book(&Mcu, 98676454354, "��Ƭ��������Ӧ��", 32);
	Create_Book(&Compile_Theory, 98745354322, "����ԭ��", 46);
	Create_Book(&Compile_Language, 96467688768, "������Գ�����ƽ̳�", 21);

/**

    ͨ�������ܷ������"ͼ�����ϵͳ"�н�����ɾ�Ĳ�Ȳ�����

**/

	return 0;
}