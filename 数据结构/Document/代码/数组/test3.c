#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int a[] = {16,47,89,42,38};
	
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		printf("%d\n", a[i]); 
	}
	
	/*
	printf("%zu\n", sizeof(a));
	printf("%zu\n", sizeof(a[0]));

	int len = sizeof(a) / sizeof(a[0]);
	printf("数组长度为%d\n", len);
	*/
	return 0;
}