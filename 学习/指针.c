#include<stdio.h>
int main(void)
{
	int sun_flower = 100;
	int* p = &sun_flower;//ָ��洢sun_flower�ĵ�ַ,��ȡ��ַ��
	printf("���sun_flower����ʵ��ֵ:%d\n", sun_flower);
	printf("ͨ��ָ�����sun_flower����ʵ��ֵ:%d\n", *p);//*�ǽ�����,���ָ��洢�ĵ�ַ��ֵ
	printf("sun_flower_address = %p\n", p);
	return 0;

}