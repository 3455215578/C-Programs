#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("a=%d, b=%d\n", *a, *b);
}

int main(int argc, char const *argv[])
{
	int m = 5;
	int n = 10;
	swap(&m, &n);
	printf("m=%d, n=%d\n", m, n);
	return 0;
}