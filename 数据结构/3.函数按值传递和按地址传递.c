#include <stdio.h>

// 按值传递 : 不会改变传入参数的值，而是把传入参数的值复制到形参中
void fcn1(int fcn1_a, int fcn1_b)
{
	fcn1_a *= 2;
	fcn1_b *= 2;

	printf("调用fnc1后，fcn1_a: %d, fcn1_b: %d\n", fcn1_a, fcn1_b);
}

// 按地址传递
void fcn2(int* fcn2_a, int* fcn2_b)
{
	*fcn2_a *= 2;
	*fcn2_b *= 2;

	printf("调用fnc2后，fcn2_a: %d, fcn2_b: %d\n", *fcn2_a, *fcn2_b);
}

int main(void)
{
	int main_a, main_b;
	main_a = 5;
	main_b = 10;

	/** 按值传递 **/
	printf("调用fnc1前，main_a: %d, main_b: %d\n\n", main_a, main_b);
	fcn1(main_a, main_b);
	printf("调用fnc1后，main_a: %d, main_b: %d\n\n", main_a, main_b);


	/** 按地址传递 **/
	printf("调用fnc2前，main_a: %d, main_b: %d\n\n", main_a, main_b);
	fcn2(&main_a, &main_b);
	printf("调用fnc2后，main_a: %d, main_b: %d\n", main_a, main_b);


	return 0;
}