#include <stdio.h>

// ��ֵ���� : ����ı䴫�������ֵ�����ǰѴ��������ֵ���Ƶ��β���
void fcn1(int fcn1_a, int fcn1_b)
{
	fcn1_a *= 2;
	fcn1_b *= 2;

	printf("����fnc1��fcn1_a: %d, fcn1_b: %d\n", fcn1_a, fcn1_b);
}

// ����ַ����
void fcn2(int* fcn2_a, int* fcn2_b)
{
	*fcn2_a *= 2;
	*fcn2_b *= 2;

	printf("����fnc2��fcn2_a: %d, fcn2_b: %d\n", *fcn2_a, *fcn2_b);
}

int main(void)
{
	int main_a, main_b;
	main_a = 5;
	main_b = 10;

	/** ��ֵ���� **/
	printf("����fnc1ǰ��main_a: %d, main_b: %d\n\n", main_a, main_b);
	fcn1(main_a, main_b);
	printf("����fnc1��main_a: %d, main_b: %d\n\n", main_a, main_b);


	/** ����ַ���� **/
	printf("����fnc2ǰ��main_a: %d, main_b: %d\n\n", main_a, main_b);
	fcn2(&main_a, &main_b);
	printf("����fnc2��main_a: %d, main_b: %d\n", main_a, main_b);


	return 0;
}