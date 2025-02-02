#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a[] = {15,22,67,43,87};
	int *p;
	p = a;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		printf("%d\n", a[i]);
	}
	
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		printf("%d\n", *(p + i));
	}
	return 0;
}