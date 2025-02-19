#include<stdio.h>
//int main(void)
//{
//	char char_1 = 'A';
//	char* p1 = &char_1;                              //1.指向单个字符
//	printf("char_1的地址:%p\n", p1);
//	printf("char_1的值:%d\n", *p1);
//	return 0;
//}

int main(void)
{
	char array_2[] = { "I LOVE YOU" };
	char* p_2 = &array_2;                            //2.指向字符数组
	printf("%c\n", *p_2);
	printf("%s\n", p_2);
	return 0;
}