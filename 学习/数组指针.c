#include<stdio.h>
int main(void)
{
	int var[] = { 10,50,100 };
	int* p = &var;
	printf("var�ĵ�ַ = %p\n", &var);
	printf("var��address = %p\n", p);

	const int MAX = 3;
	int number;
	number = 0;
	for (number = 0; number < MAX; number++)
	{
		printf("var[%d]�ĵ�ַ:%p\n", number, p);//��ָ���ʾ,��Ϊ������ָ�����
		printf("var[%d]��ֵ:%d\n", number, *p);
		p++;
	}
	return 0;
}