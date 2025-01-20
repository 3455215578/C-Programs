#include<stdio.h>//按常规构思整个程序,从主函数开始,等到需要用指针函数时将其放在主函数之上,不像常规函数定义,直接开大括号
#pragma warning(disable:4996)
char* strlong(char* str1, char* str2)//2.strlong函数接收str1和str2数组的地址
{
	printf("str1的地址:%p\n", str1);
	printf("str2的地址:%p\n", str2);
	if (strlen(str1) >= strlen(str2))
	{
		return str1;
	}
	else
	{
		return str2;
	}//3.指针函数发送str1或str2数组的地址到主函数

}
int main(void)
{
	char str1[30], str2[30], * receive;
	gets(str1);
	gets(str2);//????????
	receive = strlong(&str1, &str2);//1.主函数发送str1和str2数组的地址给strlong函数   4.主函数用新定义的receive指针接收二者其一的地址,结束!
	printf("最长的字符串:%s\n", receive);
	printf("最长字符串的地址:%p\n", receive);
	return 0;
}
