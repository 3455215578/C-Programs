#include<stdio.h>//�����湹˼��������,����������ʼ,�ȵ���Ҫ��ָ�뺯��ʱ�������������֮��,���񳣹溯������,ֱ�ӿ�������
#pragma warning(disable:4996)
char* strlong(char* str1, char* str2)//2.strlong��������str1��str2����ĵ�ַ
{
	printf("str1�ĵ�ַ:%p\n", str1);
	printf("str2�ĵ�ַ:%p\n", str2);
	if (strlen(str1) >= strlen(str2))
	{
		return str1;
	}
	else
	{
		return str2;
	}//3.ָ�뺯������str1��str2����ĵ�ַ��������

}
int main(void)
{
	char str1[30], str2[30], * receive;
	gets(str1);
	gets(str2);//????????
	receive = strlong(&str1, &str2);//1.����������str1��str2����ĵ�ַ��strlong����   4.���������¶����receiveָ����ն�����һ�ĵ�ַ,����!
	printf("����ַ���:%s\n", receive);
	printf("��ַ����ĵ�ַ:%p\n", receive);
	return 0;
}
