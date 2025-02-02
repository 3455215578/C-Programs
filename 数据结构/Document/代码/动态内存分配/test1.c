#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int *p;
	p = (int*)malloc(sizeof(int));
	*p = 15;
	printf("%d\n", *p);
	printf("%p\n", p);
	printf("%p\n", &p);
	free(p);
	return 0;
}