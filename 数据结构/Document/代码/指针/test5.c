#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a[] = {15,22,67,43,87};
	int *p;
	p = a;
	printf("%p\n", a);
	printf("%p\n", p);
	printf("%d\n", *p);
	return 0;
}