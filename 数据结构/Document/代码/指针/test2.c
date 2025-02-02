#include<stdio.h>

int main(int argc, char const *argv[])
{
	int a = 5;
	int *p = &a;
	printf("%d\n", *p);
	*p = 100;
	printf("%d\n",a);
	return 0;
}